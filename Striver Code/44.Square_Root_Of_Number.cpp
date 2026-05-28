// Given a positive integer n. Find and return its square root.
// If n is not a perfect square, then return the floor value of sqrt(n).

// Input: n = 36
// Output: 6
// Explanation: 6 is the square root of 36.

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Solution {
public:
    int floorSqrt(int n)  {

        // Starting point of binary search
        int low = 1;

        // Ending point of binary search
        int high = n;

        // Stores the current best possible answer
        int ans = 1; 

        // Binary search loop
        while(low <= high){

            // Find middle element
            int mid = (low + high)/2;

            // Check if mid is a valid square root
            if(mid <= n){

                // Store current answer
                ans = mid;

                // Move right to find a larger possible answer
                low = mid + 1;
            }

            // If mid is too large
            else if(mid > n){

                // Move left
                high = mid - 1;
            }
        }

        // Return floor square root
        return ans;
      
    }
};