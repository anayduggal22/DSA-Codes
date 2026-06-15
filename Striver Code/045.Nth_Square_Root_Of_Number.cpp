// Given two numbers N and M, find the Nth root of M.
// The Nth root of a number M is defined as a number X
// such that when X is raised to the power of N, it equals M.
// If the Nth root is not an integer, return -1.

// Input: N = 3, M = 27
// Output: 3
// Explanation: The cube root of 27 is equal to 3.

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
    int NthRoot(int N, int M)
    {

        // Starting point of binary search
        int low = 1;

        // Ending point of binary search
        int high = M;

        // Continue binary search until range becomes invalid
        while (low <= high)
        {

            // Find middle value
            int mid = (low + high) / 2;

            // Calculate mid raised to the power N
            int val = pow(mid, N);

            // If exact Nth root is found
            if (val == M)
            {
                return mid;
            }

            // If current value is smaller than M,
            // search in the right half
            else if (val < M){
                low = mid + 1;
            }

            // If current value is greater than M,
            // search in the left half
            else if(val > M){
                high = mid - 1;
            }
        }

        // If no integer Nth root exists
        return -1;
    }
};