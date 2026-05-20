// You are given a sorted array of integers arr and an integer target.
// Your task is to determine how many times target appears in arr.

// Return the count of occurrences of target in the array.

// Input: arr = [0, 0, 1, 1, 1, 2, 3], target = 1
// Output: 3
// Explanation: The number 1 appears 3 times in the array.

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Solution
{
public:
    int countOccurrences(vector<int> &nums, int target)
    {

        // Binary search range
        int low = 0;
        int high = nums.size() - 1;

        // Finding first occurrence
        // Basically LOWER BOUND:
        // first index where nums[mid] >= target

        int first = nums.size();

        while (low <= high)
        {

            int mid = (low + high) / 2;

            // Possible first occurrence found
            // Move left to search for an earlier occurrence
            if (nums[mid] >= target)
            {
                first = mid;
                high = mid - 1;
            }

            // Target lies on right side
            else
            {
                low = mid + 1;
            }
        }

        // Target does not exist in array
        if (first == nums.size() || nums[first] != target)
        {
            return -1;
        }

        // Reset binary search range
        low = 0;
        high = nums.size() - 1;

        // Finding upper bound
        // First index where nums[mid] > target

        int last = nums.size();

        while (low <= high)
        {

            int mid = (low + high) / 2;

            // Possible upper bound found
            // Move left to find smaller valid index
            if (nums[mid] > target)
            {
                last = mid;
                high = mid - 1;
            }

            // Still inside target range
            // Move right
            else
            {
                low = mid + 1;
            }
        }

        // Actual last occurrence = last - 1
        // Count = last occurrence - first occurrence + 1

        return (last - 1) - (first - 1);
    }
};