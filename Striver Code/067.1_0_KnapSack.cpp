// ===============================
// 0/1 Knapsack Problem
// ===============================
//
// Given two arrays:
// val[] -> value of each item
// wt[]  -> weight of each item
//
// Find the maximum value that can be obtained by selecting
// a subset of items such that the total weight <= W.
//
// NOTE:
// - Every item can be taken AT MOST ONCE.
//
// Time Complexities:
// Memoization      : O(N * W)
// Tabulation       : O(N * W)
// Space Optimized  : O(N * W)
//
// Space Complexities:
// Memoization      : O(N * W) + O(N) recursion stack
// Tabulation       : O(N * W)
// Space Optimized  : O(W)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:

    // ====================================================
    // MEMOIZATION
    // n represents the CURRENT INDEX (0 ... N-1)
    // ====================================================
    int fact(vector<int> &wt, vector<int> &val, int n, int W,
             vector<vector<int>> &dp)
    {
        // Base Case
        // Only first item is left
        if (n == 0)
        {
            if (wt[0] <= W)
                return val[0];

            return 0;
        }

        // Already computed
        if (dp[n][W] != -1)
            return dp[n][W];

        // Don't take current item
        int notTake = fact(wt, val, n - 1, W, dp);

        // Take current item (only if possible)
        int take = 0;

        if (wt[n] <= W)
            take = val[n] + fact(wt, val, n - 1, W - wt[n], dp);

        return dp[n][W] = max(take, notTake);
    }

    // ====================================================
    // TABULATION
    // Here n = NUMBER OF ITEMS (NOT LAST INDEX)
    // ====================================================
    int tabular(vector<int> &wt, vector<int> &val, int n, int W)
    {
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        // --------------------------
        // Base Case
        // --------------------------
        // If only first item exists,
        // we can take it whenever capacity >= wt[0]

        for (int w = wt[0]; w <= W; w++)
        {
            dp[0][w] = val[0];
        }

        // Fill remaining rows
        for (int i = 1; i < n; i++)
        {
            for (int w = 0; w <= W; w++)
            {
                int notTake = dp[i - 1][w];

                int take = 0;

                if (wt[i] <= w)
                    take = val[i] + dp[i - 1][w - wt[i]];

                dp[i][w] = max(take, notTake);
            }
        }

        return dp[n - 1][W];
    }

    // ====================================================
    // SPACE OPTIMIZATION
    //
    // IMPORTANT:
    // Traverse capacity from RIGHT TO LEFT.
    //
    // Why?
    // Because every item can be used ONLY ONCE.
    //
    // If we traverse left to right,
    // we will use the updated value of the same row,
    // which becomes Unbounded Knapsack.
    // ====================================================
    int space_optimised(vector<int> &wt, vector<int> &val, int n, int W)
    {
        vector<int> prev(W + 1, 0);

        // Base Case
        for (int w = wt[0]; w <= W; w++)
        {
            prev[w] = val[0];
        }

        for (int i = 1; i < n; i++)
        {
            // Reverse traversal is the key
            for (int w = W; w >= 0; w--)
            {
                int notTake = prev[w];

                int take = 0;

                if (wt[i] <= w)
                    take = val[i] + prev[w - wt[i]];

                prev[w] = max(take, notTake);
            }
        }

        return prev[W];
    }

    // ====================================================
    // Driver Function
    // ====================================================
    int knapsack(vector<int> &wt, vector<int> &val, int W)
    {
        int n = wt.size();

        // ---------------- Memoization ----------------
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        // return fact(wt, val, n - 1, W, dp);

        // ---------------- Tabulation -----------------
        // return tabular(wt, val, n, W);

        // ------------ Space Optimized ----------------
        return space_optimised(wt, val, n, W);
    }
};

int main()
{
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};

    int W = 50;

    Solution obj;

    cout << obj.knapsack(wt, val, W);

    return 0;
}