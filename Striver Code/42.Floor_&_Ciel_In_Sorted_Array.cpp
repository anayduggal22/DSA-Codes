// Given a sorted array nums and an integer x.
// Find the floor and ceil of x in nums.

// Floor  -> largest element <= x
// Ceil   -> smallest element >= x

// If no floor or ceil exists, return -1 for that value.

// Input : nums = [3, 4, 4, 7, 8, 10], x = 5
// Output: 4 7
// Explanation:
// Floor of 5 is 4
// Ceil of 5 is 7

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Solution
{
public:

    vector<int> getFloorAndCeil(vector<int> nums, int x)
    {

        // Binary search range
        int low = 0;
        int high = nums.size() - 1;

        // Final floor and ceil values
        int f, c;

        // Store floor index
        // Initialized with -1 because floor may not exist
        int floor = -1;

        // Finding floor:
        // Largest index where nums[mid] <= x

        while(low <= high)
        {

            int mid = (low + high) / 2;

            // Valid floor found
            // Store answer and move right
            // to search for a larger valid value
            if(nums[mid] <= x)
            {
                floor = mid;
                low = mid + 1;
            }

            // Current value too large
            // Move left
            else
            {
                high = mid - 1;
            }
        }

        // No floor exists
        if(floor == -1)
        {
            f = -1;
        }

        // Convert floor index into actual value
        else
        {
            f = nums[floor];
        }

        // Reset binary search range
        low = 0;
        high = nums.size() - 1;

        // Store ceil index
        // Initialized with nums.size()
        // because ceil may not exist
        int ciel = nums.size();

        // Finding ceil:
        // Smallest index where nums[mid] >= x

        while(low <= high)
        {

            int mid = (low + high) / 2;

            // Valid ceil found
            // Store answer and move left
            // to search for smaller valid value
            if(nums[mid] >= x)
            {
                ciel = mid;
                high = mid - 1;
            }

            // Current value too small
            // Move right
            else
            {
                low = mid + 1;
            }
        }

        // No ceil exists
        if(ciel == nums.size())
        {
            c = -1;
        }

        // Convert ceil index into actual value
        else
        {
            c = nums[ciel];
        }

        // Return floor and ceil values
        return {f, c};
    }
};