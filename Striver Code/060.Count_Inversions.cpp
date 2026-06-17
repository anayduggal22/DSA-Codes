// Given an integer array nums. Return the number of inversions in the array.

// Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

// It indicates how close an array is to being sorted.

// A sorted array has an inversion count of 0.

// An array sorted in descending order has maximum inversion.

// Input: nums = [2, 3, 7, 1, 3, 5]
// Output: 5
// Explanation:
// The responsible indexes are:
// nums[0], nums[3], values: 2 > 1 & indexes: 0 < 3
// nums[1], nums[3], values: 3 > 1 & indexes: 1 < 3
// nums[2], nums[3], values: 7 > 1 & indexes: 2 < 3
// nums[2], nums[4], values: 7 > 3 & indexes: 2 < 4
// nums[2], nums[5], values: 7 > 5 & indexes: 2 < 5

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <climits>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:

    // Merges two sorted halves and counts inversions
    void merge(vector<int>& nums, int low, int mid, int high, long long& count) {

        int left = low;       // Pointer for left half
        int right = mid + 1; // Pointer for right half

        vector<int> temp;    // Temporary array for merging

        while (left <= mid && right <= high) {

            // If left element is greater than right element,
            // then all elements from left to mid will also be
            // greater than nums[right] because the left half is sorted.
            if (nums[left] > nums[right]) {

                // Count all inversions formed with nums[right]
                count += mid - (left - 1);

                temp.push_back(nums[right]);
                right++;
            }
            else {
                temp.push_back(nums[left]);
                left++;
            }
        }

        // Copy remaining elements from left half
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        // Copy remaining elements from right half
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        // Copy merged result back into original array
        for (int i = 0; i < temp.size(); i++) {
            nums[i + low] = temp[i];
        }
    }

    // Recursive Merge Sort
    void mergesort(vector<int>& nums, int low, int high, long long& count) {

        if (low < high) {

            int mid = (low + high) / 2;

            // Sort left half
            mergesort(nums, low, mid, count);

            // Sort right half
            mergesort(nums, mid + 1, high, count);

            // Merge sorted halves and count inversions
            merge(nums, low, mid, high, count);
        }
    }

    long long int numberOfInversions(vector<int> nums) {

        int low = 0;
        int high = nums.size() - 1;

        long long count = 0;

        mergesort(nums, low, high, count);

        return count;
    }
};