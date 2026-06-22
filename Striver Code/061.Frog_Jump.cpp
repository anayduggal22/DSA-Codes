// A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step.

// To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference. The frog can jump from any step either one or two steps, provided it exists.

// Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.

// Input: heights = [2, 1, 3, 5, 4]
// Output: 2
// Explanation:
// One possible route can be,
// 0th step -> 2nd Step = abs(2 - 3) = 1
// 2nd step -> 4th step = abs(3 - 4) = 1
// Total = 1 + 1 = 2.

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

    // Returns the minimum energy required to reach step n
    int fact(int n, vector<int>& heights, vector<int>& arr) {

        // Base case: already at the 0th step, no energy needed
        if (n == 0) {
            return 0;
        }

        // If already computed, return the stored answer
        if (arr[n] != -1) {
            return arr[n];
        }

        // Option 1: Jump from the previous step (n-1) to nth step
        int x = fact(n - 1, heights, arr)
                + abs(heights[n] - heights[n - 1]);

        // Initialize second option with a large value
        int y = INT_MAX;

        // Option 2: Jump from the step before previous (n-2) to nth step
        // Only possible if n-2 exists
        if (n - 2 >= 0) {
            y = fact(n - 2, heights, arr)
                + abs(heights[n] - heights[n - 2]);
        }

        // Store and return the minimum energy among the two choices
        return arr[n] = min(x, y);
    }

    int frogJump(vector<int>& heights) {

        // DP array initialized with -1 (means not computed yet)
        vector<int> arr(heights.size(), -1);

        // Find minimum energy required to reach the last step
        return fact(heights.size() - 1, heights, arr);
    }
};