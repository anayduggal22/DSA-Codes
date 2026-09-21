// Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices. In other words, determine where to place parentheses to minimize the number of multiplications.

// Given an array nums of size n. Dimension of matrix Ai ( 0 < i < n ) is nums[i - 1] x nums[i].Find a minimum number of multiplications needed to multiply the chain.

// Input : nums = [10, 15, 20, 25]
// Output : 8000
// Explanation : There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
// If we multiply in order- A1*(A2*A3), then number of multiplications required are 11250.
// If we multiply in order- (A1*A2)*A3, then number of multiplications required are 8000.
// Thus minimum number of multiplications required is 8000.

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:

    // Finds the minimum multiplication cost for matrices i to j
    int fact(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {

        // A single matrix requires no multiplication
        if (i == j) {
            return 0;
        }

        // Return already calculated result
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int m = INT_MAX;

        // Try every possible position to split the matrix chain
        for (int k = i; k < j; k++) {

            // Cost = left part + right part + cost of multiplying both parts
            int steps = fact(i, k, nums, dp)
                      + fact(k + 1, j, nums, dp)
                      + (nums[i - 1] * nums[k] * nums[j]);

            m = min(m, steps);
        }

        // Store and return the minimum cost
        return dp[i][j] = m;
    }

    int tab(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        // A single matrix needs 0 multiplications
        for (int i = 0; i < n; i++) {
            dp[i][i] = 0;
        }

        // Calculate for increasing chain lengths
        for (int i = n - 1; i >= 1; i--) {

            for (int j = i + 1; j < n; j++) {

                int m = INT_MAX;

                // Try every possible partition point
                for (int k = i; k < j; k++) {

                    int steps = dp[i][k]
                              + dp[k + 1][j]
                              + (nums[i - 1] * nums[k] * nums[j]);

                    m = min(m, steps);
                }

                dp[i][j] = m;
            }
        }

        // Minimum cost to multiply all matrices
        return dp[1][n - 1];
    }

    int matrixMultiplication(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        // Find minimum cost from the first matrix to the last matrix
        return fact(1, n - 1, nums, dp);
    }
};