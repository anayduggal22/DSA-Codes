// Given an array nums of n integers, where nums[i] represents the
// number of pages in the i-th book, and an integer m representing
// the number of students, allocate all the books to the students
// so that:
// 1. Each student gets at least one book
// 2. Each book is allocated to only one student
// 3. Allocation is contiguous
//
// We have to minimize the maximum pages assigned to a student.
//
// Example:
// nums = [12, 34, 67, 90], m = 2
// Output = 113
//
// Explanation:
// Allocation:
// 12, 34, 67 | 90
//
// Maximum pages assigned = 113

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <climits>
#include <math.h>

using namespace std;

class Solution
{
public:

    // Function to count how many students are needed
    // if one student can read at most "weight" pages
    int count(vector<int> &nums, int weight)
    {
        int c = 1; // Initially first student
        int last = nums[0]; // First book assigned

        for (int i = 1; i < nums.size(); i++)
        {

            // If current book can be added to current student
            if (last + nums[i] <= weight)
            {
                last += nums[i];
            }

            // Otherwise assign to next student
            else
            {
                c++;
                last = nums[i];
            }
        }

        return c;
    }

    int findPages(vector<int> &nums, int m)
    {

        // If students are more than books
        // allocation is not possible
        if (m > nums.size())
        {
            return -1;
        }

        int n = 0;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            // Minimum answer can never be smaller
            // than maximum element in array
            n = max(n, nums[i]);

            // Maximum answer can be sum of all books
            // when only one student gets all books
            sum += nums[i];
        }

        int low = n;
        int high = sum;

        int ans = 0;

        while (low <= high)
        {

            // Mid pages assigned as maximum limit
            int mid = low + (high - low) / 2;

            // Count students needed for this limit
            int c = count(nums, mid);

            // If students required are less than or equal to m
            // then this answer is possible
            if (c <= m)
            {
                ans = mid;

                // Try finding smaller answer
                high = mid - 1;
            }

            // If more students are needed
            // increase maximum pages limit
            else
            {
                low = mid + 1;
            }
        }

        // Minimum possible maximum pages
        return ans;
    }
};