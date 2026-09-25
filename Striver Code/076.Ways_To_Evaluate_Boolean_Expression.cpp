// You are given a string expr consisting of the characters
// 'T' — represents true
// 'F' — represents false
// '&' — the logical AND operator
// '|' — the logical OR operator
// '^' — the logical XOR (exclusive-or) operator
// expr is guaranteed to follow the pattern operand operator operand operator … operand (i.e. it always starts and ends with an operand and no two operators are adjacent).

// Return the number of distinct ways to fully parenthesize expr such that the whole expression evaluates to true.
// Because the answer can be very large, return it modulo 109+7.

// Example 1:
// Input: expr = "T|T&F^T"
// Output: 4
// Explanation:
// The expression can be parenthesized as follows (✓ marks variants that evaluate to true):
// 1. ((T|T)&(F^T)) ✓
// 2. (T|(T&(F^T))) ✓
// 3. (((T|T)&F)^T) ✓
// 4. (T|((T&F)^T)) ✓
// 5. ((T|(T&F))^T)   → false
// 6. (T|T)&F^T     → false
// Therefore 4 distinct parenthesizations evaluate to true.

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:

    int fact(int i, int j, int istrue,
             vector<vector<vector<int>>>& dp,
             string const& expression) {

        // Base case
        if(i > j) {
            return 0;
        }

        // If only one operand is present
        if(i == j && istrue == 1) {
            return expression[i] == 'T';
        }

        if(i == j && istrue == 0) {
            return expression[i] == 'F';
        }

        // Already calculated
        if(dp[i][j][istrue] != -1) {
            return dp[i][j][istrue];
        }

        int ways = 0;

        // Try every operator as the partition point
        for(int k = i + 1; k <= j - 1; k += 2) {

            int lt = fact(i, k - 1, 1, dp, expression);
            int lf = fact(i, k - 1, 0, dp, expression);

            int rt = fact(k + 1, j, 1, dp, expression);
            int rf = fact(k + 1, j, 0, dp, expression);

            // AND operation
            if(expression[k] == '&') {

                if(istrue == 1) {
                    // T & T = T
                    ways += lt * rt;
                }
                else {
                    // T&F, F&T, F&F = F
                    ways += lt * rf + lf * rt + lf * rf;
                }
            }

            // OR operation
            else if(expression[k] == '|') {

                if(istrue == 1) {
                    // T|T, T|F, F|T = T
                    ways += lt * rt + lt * rf + lf * rt;
                }
                else {
                    // F|F = F
                    ways += lf * rf;
                }
            }

            // XOR operation
            else if(expression[k] == '^') {

                if(istrue == 1) {
                    // T^F and F^T = T
                    ways += lt * rf + lf * rt;
                }
                else {
                    // T^T and F^F = F
                    ways += lt * rt + lf * rf;
                }
            }
        }

        return dp[i][j][istrue] = ways;
    }

    int countTrue(string s) {

        int n = s.length();

        // istrue = 0 -> false
        // istrue = 1 -> true
        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(n, vector<int>(2, -1))
        );

        // Find number of ways for the complete expression
        // to evaluate to true
        return fact(0, n - 1, 1, dp, s);
    }
};