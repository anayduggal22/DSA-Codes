// Given an array arr of n integers and an integer diff, count the number of ways to partition the array into two subsets S1 and S2 such that:

// ∣S1−S2∣ = diff and S1 ≥ S2
// Where |S1| and |S2| are sum of Subsets S1 and S2 respectively.

// Return the result modulo 109 + 7.

// Note: A partition means that the union of S1 and S2 is the original array, and no element is left out or used twice — every element of the array belongs to exactly one of the two subsets.

// Input: arr = [1, 1, 2, 3], diff = 1
// Output: 3
// Explanation: The subsets are [1, 2] and [1, 3], [1, 3] and [1, 2], [1, 1, 2] and [3].

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
    // ---------------- Memoization ----------------
    int fact(vector<int> &nums, int n, vector<vector<int>> &dp, int k)
    {
        // Base Case
        if (n == 0)
        {
            // If first element is 0 and target is also 0,
            // there are two possibilities:
            // {} and {0}
            if (nums[0] == 0 && k == 0)
            {
                return 2;
            }

            // Either take nums[0] or don't take anything
            else if (nums[0] == k || k == 0)
            {
                return 1;
            }

            return 0;
        }

        // Already computed
        if (dp[n][k] != -1)
        {
            return dp[n][k];
        }

        // Don't take current element
        int nottake = fact(nums, n - 1, dp, k);

        // Take current element
        int take = 0;

        if (k >= nums[n])
        {
            take = fact(nums, n - 1, dp, k - nums[n]);
        }

        // Store answer
        return dp[n][k] = (nottake + take) % 1000000007;
    }

    // ---------------- Tabulation ----------------
    int tabulation(vector<int> &nums, int n, vector<vector<int>> &dp, int k)
    {
        // Base Case

        // If first element is 0
        if (nums[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        // If first element itself can make the target
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

    // ---------------- Space Optimized ----------------
    int space_efficient(vector<int> &nums, int n, int k)
    {
        vector<int> prev(k + 1, 0);
        vector<int> curr(k + 1, 0);

        // Base Case
        if (nums[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;

        if (nums[0] != 0 && nums[0] <= k)
            prev[nums[0]] = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j <= k; j++)
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

public:
    int countPartitions(int n, int diff, vector<int> &arr)
    {
        // S1 - S2 = diff
        // S1 + S2 = total
        //
        // Therefore,
        // S2 = (total - diff) / 2
        //
        // Count subsets having sum = target

        int total = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            total += arr[i];
        }

        // Impossible cases
        if ((total - diff) < 0 || (total - diff) % 2 != 0)
        {
            return 0;
        }

        int target = (total - diff) / 2;

        // Uncomment the approach you want

        // Memoization
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return fact(arr, n - 1, dp, target);

        // Tabulation
        // vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        // return tabulation(arr, n, dp, target);

        // Space Optimized
        // return space_efficient(arr, n, target);
    }
};