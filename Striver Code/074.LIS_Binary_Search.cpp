// Given an integer array nums, return the length of the longest
// strictly increasing subsequence.

// A subsequence is a sequence derived from an array by deleting
// some or no elements without changing the order of the remaining elements.
// For example, [3, 6, 2, 7] is a subsequence of [0, 3, 1, 6, 2, 2, 7].

// The task is to find the length of the longest subsequence in which
// every element is greater than the previous one.

// Input: nums = [10, 9, 2, 5, 3, 7, 101, 18]
// Output: 4
// Explanation: The longest increasing subsequence is [2, 3, 7, 101],
// and its length is 4.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:

    // Finds the first index in temp where temp[index] >= target.
    // This is called "lower bound".
    //
    // Example:
    // temp = [2, 3, 7]
    // target = 5
    // First element >= 5 is 7, so return index 2.
    int lower_bound(int target, vector<int>& temp)
    {
        int low = 0;
        int high = temp.size() - 1;

        // Binary search
        while (low <= high)
        {
            // Find the middle index
            int mid = low + (high - low) / 2;

            // If temp[mid] is greater than or equal to target,
            // the answer can be at mid or somewhere to the left.
            if (temp[mid] >= target)
            {
                high = mid - 1;
            }
            // If temp[mid] is smaller than target,
            // we need to search on the right side.
            else
            {
                low = mid + 1;
            }
        }

        // low will point to the first element >= target
        return low;
    }

    int LIS(vector<int>& nums)
    {
        // If the array is empty, LIS length is 0.
        if (nums.empty())
            return 0;

        // temp stores the smallest possible ending element
        // for increasing subsequences of different lengths.
        //
        // IMPORTANT:
        // temp does not necessarily contain the actual LIS.
        // Its size represents the length of the LIS.
        vector<int> temp;

        // Initially, the first element itself forms
        // an increasing subsequence of length 1.
        temp.push_back(nums[0]);

        // Process the remaining elements
        for (int i = 1; i < nums.size(); i++)
        {
            // If current element is greater than the last element
            // of temp, we can extend the increasing subsequence.
            if (nums[i] > temp.back())
            {
                temp.push_back(nums[i]);
            }
            else
            {
                // Otherwise, find the first element in temp
                // that is >= nums[i].
                int index = lower_bound(nums[i], temp);

                // Replace that element with nums[i].
                //
                // This gives us a smaller possible ending value,
                // which gives us a better chance of extending
                // the subsequence in the future.
                temp[index] = nums[i];
            }
        }

        // The size of temp represents the length
        // of the longest increasing subsequence.
        return temp.size();
    }
};