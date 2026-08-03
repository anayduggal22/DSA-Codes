// Given two integer arrays, val and wt, each of size N, representing the values
// and weights of N items respectively, and an integer W representing the maximum
// capacity of the knapsack, find the maximum value that can be obtained.
//
// Infinite supply of every item is available (Unbounded Knapsack).
//
// Input:
// val = [5, 11, 13]
// wt  = [2, 4, 6]
// W   = 10
//
// Output:
// 27
//
// Explanation:
// Pick weight 4 twice and weight 2 once.
// Total value = 11 + 11 + 5 = 27.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>      // For INT_MIN

using namespace std;

class Solution
{
public:

    // ---------------- Memoization ----------------
    int fact(vector<int> &wt, vector<int> &val, int n, int W,
             vector<vector<int>> &dp)
    {
        // Base Case:
        // Only the first item (index 0) is available.
        // Since it is an unbounded knapsack, we can take it
        // as many times as possible.
        if (n == 0)
        {
            return (W / wt[0]) * val[0];
        }

        // Return already computed state.
        if (dp[n][W] != -1)
        {
            return dp[n][W];
        }

        // Option 1: Do not take the current item.
        int nottake = fact(wt, val, n - 1, W, dp);

        // Option 2: Take the current item.
        // Stay at the same index because the item can be picked again.
        int take = INT_MIN;

        if (wt[n] <= W)
        {
            take = val[n] + fact(wt, val, n, W - wt[n], dp);
        }

        // Store and return the maximum value possible.
        return dp[n][W] = max(nottake, take);
    }

    // ---------------- Tabulation ----------------
    int tabulation(vector<int> &wt, vector<int> &val, int n, int W,
                   vector<vector<int>> &dp)
    {
        // Base Case:
        // Fill the first row using only item 0.
        for (int w = 0; w <= W; w++)
        {
            dp[0][w] = (w / wt[0]) * val[0];
        }

        // Build the DP table.
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                // Do not take the current item.
                int nottake = dp[i - 1][j];

                // Take the current item.
                // Since this is Unbounded Knapsack,
                // remain in the same row after taking.
                int take = INT_MIN;

                if (wt[i] <= j)
                {
                    take = val[i] + dp[i][j - wt[i]];
                }

                // Store the better of the two choices.
                dp[i][j] = max(nottake, take);
            }
        }

        return dp[n - 1][W];
    }

    // ---------------- One Array Space Optimization ----------------
    int One_Array_Space_Optimisation(vector<int> &wt, vector<int> &val,
                                     int n, int W)
    {
        vector<int> prev(W + 1, -1);

        // Base Case:
        // Using only the first item.
        for (int w = 0; w <= W; w++)
        {
            prev[w] = (w / wt[0]) * val[0];
        }

        // Process every remaining item.
        for (int i = 1; i < n; i++)
        {
            // Traverse from left to right.
            // This allows reuse of the current item multiple times.
            for (int j = 0; j <= W; j++)
            {
                // Do not take the current item.
                int nottake = prev[j];

                // Take the current item.
                // Since we move left to right,
                // prev[j - wt[i]] already contains the updated answer
                // for the current row.
                int take = INT_MIN;

                if (wt[i] <= j)
                {
                    take = val[i] + prev[j - wt[i]];
                }

                // Store the best answer for this capacity.
                prev[j] = max(nottake, take);
            }
        }

        return prev[W];
    }

    int unboundedKnapsack(vector<int> &wt, vector<int> &val, int n, int W)
    {
        // dp[i][w] = Maximum value using items [0...i]
        // with knapsack capacity w.
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));

        // Memoization
        return fact(wt, val, n - 1, W, dp);

        // Tabulation
        // return tabulation(wt, val, n, W, dp);

        // Space Optimisation
        // return One_Array_Space_Optimisation(wt, val, n, W);
    }
};