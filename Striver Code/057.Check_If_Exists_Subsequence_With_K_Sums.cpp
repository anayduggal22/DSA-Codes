// Given an array nums and an integer k. R﻿eturn true if there exist subsequences such that the sum of all elements in subsequences is equal to k else false.

// Input : nums = [1, 2, 3, 4, 5] , k = 8
// Output : Yes
// Explanation : The subsequences like [1, 2, 5] , [1, 3, 4] , [3, 5] sum up to 8.

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
    bool combinations(int index, vector<int> &nums,
                      int sum, int k)
    {
        // Base case: all elements have been considered
        if (index == nums.size())
        {
            // Return true if the current subsequence sum equals k
            if (sum == k)
            {
                return true;
            }

            return false;
        }

        // Pick the current element and add it to the sum
        sum += nums[index];

        // If a valid subsequence is found, stop further recursion
        if (combinations(index + 1, nums, sum, k) == true)
        {
            return true;
        }

        // Backtrack: remove the picked element from the sum
        sum -= nums[index];

        // Do not pick the current element
        if (combinations(index + 1, nums, sum, k) == true)
        {
            return true;
        }

        // No valid subsequence found in either branch
        return false;
    }

    bool checkSubsequenceSum(vector<int> &nums, int k)
    {
        int sum = 0;
        int index = 0;

        // Start recursion from index 0
        return combinations(index, nums, sum, k);
    }
};