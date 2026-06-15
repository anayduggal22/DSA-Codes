// Given a 2D array matrix that is row-wise sorted.
// Find the median of the matrix.
//
// Example:
// Input:
// [ [1, 4, 9],
//   [2, 5, 6],
//   [3, 7, 8] ]
//
// Output: 5

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    // Function to count how many elements
    // are <= mid in the whole matrix
    int count(vector<vector<int>> &matrix, int mid)
    {

        int c = 0;

        // Traverse every row
        for (int i = 0; i < matrix.size(); i++)
        {

            int low = 0;
            int high = matrix[0].size() - 1;

            // Stores upper bound index
            // Default = size of row
            // (means all elements are <= mid)
            int temp = matrix[0].size();

            // Binary Search for Upper Bound
            while (low <= high)
            {

                int m = (low + high) / 2;

                // If current element > mid,
                // store index and move left
                if (matrix[i][m] > mid)
                {
                    temp = m;
                    high = m - 1;
                }

                // Otherwise move right
                else
                {
                    low = m + 1;
                }
            }

            // temp represents:
            // first index where value > mid
            //
            // Therefore:
            // number of elements <= mid = temp
            c += temp;
        }

        return c;
    }

    int findMedian(vector<vector<int>> &matrix)
    {

        // Minimum element in matrix
        int m = INT_MAX;

        // Maximum element in matrix
        int M = INT_MIN;

        // Find search space
        for (int i = 0; i < matrix.size(); i++)
        {

            m = min(m, matrix[i][0]);

            M = max(M, matrix[i][matrix[0].size() - 1]);
        }

        int low = m;
        int high = M;

        int ans = 0;

        // Binary Search on Answer
        while (low <= high)
        {

            int mid = (low + high) / 2;

            // Count elements <= mid
            int c = count(matrix, mid);

            // Median position
            int req = (matrix.size() * matrix[0].size()) / 2;

            // If enough elements are <= mid,
            // mid can be the answer
            if (c > req)
            {
                ans = mid;
                high = mid - 1;
            }

            // Need larger value
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};