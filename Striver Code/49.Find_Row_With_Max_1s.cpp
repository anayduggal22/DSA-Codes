// Given a non-empty grid mat consisting of only 0s and 1s, where all the rows are sorted in ascending order, find the index of the row with the maximum number of ones.

// If two rows have the same number of ones, consider the one with a smaller index. If no 1 exists in the matrix, return -1.

// Input : mat = [ [1, 1, 1], [0, 0, 1], [0, 0, 0] ]
// Output: 0
// Explanation: The row with the maximum number of ones is 0 (0 - indexed).

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
    // Function to count number of 1s in a row
    // using Binary Search (Lower Bound concept)
    int count(vector<vector<int>> &mat, int i)
    {
        // Stores index of first occurrence of 1
        int index = 0;

        // Flag to check whether any 1 exists
        int done = 0;

        int low = 0;
        int high = mat[0].size() - 1;

        // Binary Search
        while (low <= high)
        {
            int mid = (low + high) / 2;

            // If 1 found, store index
            // and move left to find first 1
            if (mat[i][mid] == 1)
            {
                done = 1;
                index = mid;
                high = mid - 1;
            }

            // If 0, move right
            else
            {
                low = mid + 1;
            }
        }

        // No 1 exists in this row
        if (done != 1)
        {
            return 0;
        }

        // Count of 1s =
        // total columns - first index of 1
        return mat[0].size() - index;
    }

    int rowWithMax1s(vector<vector<int>> &mat)
    {
        // Maximum number of 1s found so far
        int m = 0;

        // Answer row index
        int ans = -1;

        // Traverse every row
        for (int i = 0; i < mat.size(); i++)
        {
            // Count 1s in current row
            int c = count(mat, i);

            // Update answer if current row
            // has more 1s
            if (c > m)
            {
                m = c;
                ans = i;
            }
        }

        return ans;
    }
};