// Given an array arr of n integers and an integer K, count the number of subsets of the given array that have a sum equal to K. Return the result modulo (109 + 7).

// Input: arr = [2, 3, 5, 16, 8, 10], K = 10
// Output: 3
// Explanation: The subsets are [2, 8], [10], and [2, 3, 5].

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <climits>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // Memoization
    int fact(vector<int> &nums, int n, vector<vector<int>> &dp, int k)
    {
        if (n == 0)
        {
            if (nums[0] == 0 && k == 0)
            {
                return 2; // {} and {0}
            }
            else if (nums[0] == k || k == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        if (dp[n][k] != -1)
        {
            return dp[n][k];
        }

        int nottake = fact(nums, n - 1, dp, k);

        int take = 0;

        if (k >= nums[n])
        {
            take = fact(nums, n - 1, dp, k - nums[n]);
        }

        return dp[n][k] = (nottake + take) % 1000000007;
    }

    // Tabulation
    int tabulation(vector<int> &nums, int n, vector<vector<int>> &dp, int k)
    {
        // Base case
        if (nums[0] == 0)
            dp[0][0] = 2; // {} and {0}
        else
            dp[0][0] = 1;

        if (nums[0] != 0 && nums[0] <= k)
            dp[0][nums[0]] = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j <= k; j++)
            {
                // Don't take current element
                int nottake = dp[i - 1][j];

                // Take current element
                int take = 0;

                if (j >= nums[i])
                {
                    take = dp[i - 1][j - nums[i]];
                }

                // Store answer
                dp[i][j] = (take + nottake) % 1000000007;
            }
        }

        return dp[nums.size() - 1][k];
    }

    // Space Optimized
    int space_efficient(vector<int> &nums, int n, int k)
    {
        vector<int> prev(k + 1, 0);
        vector<int> curr(k + 1, 0);

        // Base case
        if (nums[0] == 0)
            prev[0] = 2; // {} and {0}
        else
            prev[0] = 1;

        if (nums[0] != 0 && nums[0] <= k)
            prev[nums[0]] = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            curr[0] = 1;

            for (int j = 1; j <= k; j++)
            {
                // Don't take current element
                int nottake = prev[j];

                // Take current element
                int take = 0;

                if (j >= nums[i])
                {
                    take = prev[j - nums[i]];
                }

                // Store answer
                curr[j] = (take + nottake) % 1000000007;
            }

            // Move current row to previous
            prev = curr;
        }

        return prev[k];
    }

    int perfectSum(vector<int> &nums, int k)
    {

        vector<vector<int>> dp(nums.size(), vector<int>(k + 1, -1));

        int n = nums.size() - 1;

        return fact(nums, n, dp, k);
    }
};