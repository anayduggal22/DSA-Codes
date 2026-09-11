// Given an array of n integers arr, return the Longest Increasing Subsequence (LIS) that is Index-wise Lexicographically Smallest.

// The Longest Increasing Subsequence (LIS) is the longest subsequence where all elements are in strictly increasing order.

// A subsequence A1 is Index-wise Lexicographically Smaller than another subsequence A2 if, at the first position where A1 and A2 differ, the element in A1 appears earlier in the array arr than corresponding element in S2.

// Your task is to return the LIS that is Index-wise Lexicographically Smallest from the given array.

// Input: arr = [10, 22, 9, 33, 21, 50, 41, 60, 80]
// Output: [10, 22, 33, 50, 60, 80]
// Explanation: The LIS is [10, 22, 33, 41, 60, 80] and it is the index-wise lexicographically smallest.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:

    // dp[i] = length of LIS ending at index i
    // index[i] = previous index used to form LIS ending at i

    int tabulation(vector<int> &nums, vector<int> &index)
    {
        int n = nums.size();

        // Every element itself is an LIS of length 1
        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i] &&
                    dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;

                    // Store previous index
                    index[i] = j;
                }
            }
        }

        // Find the index where the longest LIS ends
        int m = 0;
        int lastindex = 0;

        for (int i = 0; i < n; i++)
        {
            if (m < dp[i])
            {
                m = dp[i];
                lastindex = i;
            }
        }

        return lastindex;
    }


    vector<int> longestIncreasingSubsequence(vector<int> &arr)
    {
        int n = arr.size();

        // index[i] stores the previous index of i
        vector<int> index(n);

        // Initially, every element points to itself
        for (int i = 0; i < n; i++)
        {
            index[i] = i;
        }

        int lastindex = tabulation(arr, index);

        vector<int> ans;

        // Start from the last element of the LIS
        ans.push_back(arr[lastindex]);

        // Follow the previous indices
        while (index[lastindex] != lastindex)
        {
            lastindex = index[lastindex];

            ans.push_back(arr[lastindex]);
        }

        // We reconstructed the LIS backwards
        reverse(ans.begin(), ans.end());

        return ans;
    }
};