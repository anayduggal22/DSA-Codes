// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// A subsequence is a sequence derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3, 6, 2, 7] is a subsequence of [0, 3, 1, 6, 2, 2, 7].

// The task is to find the length of the longest subsequence in which every element is greater than the previous one.

// Input: nums = [10, 9, 2, 5, 3, 7, 101, 18]
// Output: 4
// Explanation: The longest increasing subsequence is [2, 3, 7, 101], and its length is 4.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:

    // =========================================================
    // 1. RECURSION + MEMOIZATION
    // =========================================================

    int fact(vector<int> &nums, int index, int previndex,
             vector<vector<int>> &dp)
    {
        // No elements left
        if (index == nums.size())
        {
            return 0;
        }

        // previndex + 1 because previndex can be -1
        if (dp[index][previndex + 1] != -1)
        {
            return dp[index][previndex + 1];
        }

        // Don't take current element
        int l1 = fact(nums, index + 1, previndex, dp);

        int l2 = 0;

        // Take current element if it is greater than previous
        if (previndex == -1 || nums[index] > nums[previndex])
        {
            l2 = 1 + fact(nums, index + 1, index, dp);
        }

        return dp[index][previndex + 1] = max(l1, l2);
    }


    // =========================================================
    // 2. TABULATION
    // =========================================================

    int tab(vector<int> &nums)
    {
        int n = nums.size();

        // +1 row for index + 1
        // +1 column because previndex can be -1
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            // previndex can be -1 to index - 1
            for (int previndex = index - 1;
                 previndex >= -1;
                 previndex--)
            {
                // Don't take
                int l1 = dp[index + 1][previndex + 1];

                int l2 = 0;

                // Take
                if (previndex == -1 || nums[index] > nums[previndex])
                {
                    l2 = 1 + dp[index + 1][index + 1];
                }

                dp[index][previndex + 1] = max(l1, l2);
            }
        }

        // index = 0, previndex = -1
        return dp[0][0];
    }


    // =========================================================
    // 3. SPACE OPTIMIZATION
    // =========================================================

    int space(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> ahead(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            for (int previndex = index - 1;
                 previndex >= -1;
                 previndex--)
            {
                // Don't take
                int l1 = ahead[previndex + 1];

                int l2 = 0;

                // Take
                if (previndex == -1 || nums[index] > nums[previndex])
                {
                    l2 = 1 + ahead[index + 1];
                }

                curr[previndex + 1] = max(l1, l2);
            }

            // Move current row to ahead
            ahead = curr;

            // Reset current row
            curr.assign(n + 1, 0);
        }

        return ahead[0];
    }


    // =========================================================
    // 4. STANDARD O(n²) DP
    // =========================================================
    //
    // dp[i] = length of LIS ending at index i
    //
    // If nums[j] < nums[i], then nums[i] can be added
    // after the LIS ending at j.
    //
    // dp[i] = max(dp[i], dp[j] + 1)
    // =========================================================

    int tabulation(vector<int> &nums)
    {
        int n = nums.size();

        // Every element itself is an LIS of length 1
        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        // LIS can end at any index
        int m = 0;

        for (int i = 0; i < n; i++)
        {
            m = max(m, dp[i]);
        }

        return m;
    }


    // =========================================================
    // LIS FUNCTION
    // =========================================================

    int LIS(vector<int> &nums)
    {
        int n = nums.size();

        // dp[index][previndex + 1]
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return fact(nums, 0, -1, dp);
    }
};