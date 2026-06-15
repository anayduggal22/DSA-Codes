// Given an array nums and an integer k.Return the number of non-empty subsequences of nums such that the sum of all elements in the subsequence is equal to k.

// Input : nums = [4, 9, 2, 5, 1] , k = 10
// Output : 2
// Explanation : The possible subsets with sum k are [9, 1] , [4, 5, 1].

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
    void combinations(int index, vector<int> &nums,
                      vector<vector<int>> &ans, vector<int> &ds,
                      int sum, int k)
    {
        // Base case: all elements have been processed
        if (index == nums.size())
        {
            // Store the subsequence if its sum equals k
            if (sum == k)
            {
                ans.push_back(ds);
            }

            return;
        }

        // Pick the current element
        ds.push_back(nums[index]);
        sum += nums[index];
        combinations(index + 1, nums, ans, ds, sum, k);

        // Backtrack: remove the picked element
        ds.pop_back();
        sum -= nums[index];

        // Do not pick the current element
        combinations(index + 1, nums, ans, ds, sum, k);
    }

    int countSubsequenceWithTargetSum(vector<int> &nums, int k)
    {
        vector<vector<int>> ans; // Stores all valid subsequences
        vector<int> ds;          // Current subsequence

        int sum = 0;
        int index = 0;

        combinations(index, nums, ans, ds, sum, k);

        // Return the count of valid subsequences
        return ans.size();
    }
};