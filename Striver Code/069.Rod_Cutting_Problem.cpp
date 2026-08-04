// Given a rod of length N inches and an array price[] where price[i] denotes the value of a piece of rod of length i inches (1-based indexing). Determine the maximum value obtainable by cutting up the rod and selling the pieces. Make any number of cuts, or none at all, and sell the resulting pieces.

// Input: price = [1, 6, 8, 9, 10, 19, 7, 20], N = 8

// Output: 25

// Explanation: Cut the rod into lengths of 2 and 6 for a total price of 6 + 19= 25.

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution{
public:

    // -------------------- Memoization --------------------
    int fact(vector<int>& price, vector<vector<int>>& dp, int index, int n){

        // Base Case:
        // If we are only allowed to use rod length = 1,
        // then the whole remaining rod has to be cut into pieces of length 1.
        if(index == 0){

            // Number of pieces = n
            // Value of each piece = price[0]
            return price[0] * n;
        }

        // If already calculated, return it.
        if(dp[index][n] != -1){
            return dp[index][n];
        }

        // Option 1: Don't cut using the current rod length.
        int nottake = fact(price, dp, index - 1, n);

        // Option 2: Cut using the current rod length.
        int take = INT_MIN;

        // Current rod length = index + 1
        if(index + 1 <= n){

            // Since this is an Unbounded Knapsack,
            // we stay at the same index because we can use this rod length again.
            take = price[index] + fact(price, dp, index, n - (index + 1));
        }

        // Store and return the maximum value.
        return dp[index][n] = max(nottake, take);
    }


    // -------------------- One Array Space Optimisation --------------------
    int One_Array_Space_Optimisation(vector<int>& price, int index, int n){

        // prev[j] = Maximum value obtainable for rod length j.
        vector<int> prev(n + 1, 0);

        // Base Case:
        // If only rod length = 1 is available.
        for(int a = 0; a <= n; a++){

            // We need 'a' pieces of length 1.
            prev[a] = price[0] * a;
        }

        // Try every rod length from 2 to N.
        for(int i = 1; i <= index; i++){

            // Traverse from left to right.
            // Left-to-right is necessary because this is an Unbounded Knapsack.
            for(int j = 0; j <= n; j++){

                // Don't take the current rod length.
                int nottake = prev[j];

                // Take the current rod length.
                int take = INT_MIN;

                // Current rod length = i + 1
                if(i + 1 <= j){

                    // Since we can use the same rod length again,
                    // use prev[] itself after reducing the rod length.
                    take = price[i] + prev[j - (i + 1)];
                }

                // Store the better option.
                prev[j] = max(nottake, take);
            }
        }

        // Answer for rod length = n.
        return prev[n];
    }


    int rodCutting(vector<int>& price, int n){

        // DP table for Memoization.
        vector<vector<int>> dp(price.size(), vector<int>(n + 1, -1));

        // Uncomment this to use Memoization.
        // return fact(price, dp, price.size() - 1, n);

        // One Array Space Optimisation.
        return One_Array_Space_Optimisation(price, price.size() - 1, n);
    }
};