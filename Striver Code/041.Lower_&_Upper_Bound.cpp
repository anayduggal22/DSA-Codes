// Give LOWER BOUND  -> smallest index where nums[i] >= target
// Give UPPER BOUND  -> smallest index where nums[i] > target

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Solution
{
public:

    // Returns:
    // {lower_bound, upper_bound}
    pair<int, int> lower_and_upper_bound(vector<int> &nums, int target)
    {

        // Binary search range
        int low = 0;
        int high = nums.size() - 1;

        // LOWER BOUND
        // First index where nums[i] >= target

        int lower_bound = nums.size();

        while (low <= high)
        {

            int mid = (low + high) / 2;

            // Valid lower bound found
            // Store answer and move left
            // to search for smaller valid index
            if (nums[mid] >= target)
            {
                lower_bound = mid;
                high = mid - 1;
            }

            // Target lies on right side
            else
            {
                low = mid + 1;
            }
        }

        // Reset binary search range
        low = 0;
        high = nums.size() - 1;

        // UPPER BOUND
        // First index where nums[i] > target

        int upper_bound = nums.size();

        while (low <= high)
        {

            int mid = (low + high) / 2;

            // Valid upper bound found
            // Store answer and move left
            // to search for smaller valid index
            if (nums[mid] > target)
            {
                upper_bound = mid;
                high = mid - 1;
            }

            // Still inside target range
            // Move right
            else
            {
                low = mid + 1;
            }
        }

        // Return both bounds
        return {lower_bound, upper_bound};
    }
};