// A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step, and an integer k.

// To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference. The frog can jump from the ith step to any step in the range [i + 1, i + k], provided it exists.

// Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.

// Input: heights = [10, 5, 20, 0, 15], k = 2
// Output: 15
// Explanation:
// 0th step -> 2nd step, cost = abs(10 - 20) = 10
// 2nd step -> 4th step, cost = abs(20 - 15) = 5
// Total cost = 10 + 5 = 15.

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
    int fact(int n, int k, vector<int>& heights, vector<int>& arr) {

        // Base case: already at the 0th step, so no energy is needed
        if (n == 0) {
            return 0;
        }

        // If the answer for step n is already computed, return it
        if (arr[n] != -1) {
            return arr[n];
        }

        // Initialize minimum energy with a very large value
        int m = INT_MAX;

        // Try all possible jumps from 1 to k steps back
        for (int i = 1; i <= k; i++) {

            // Check if the previous step exists
            if (n - i >= 0) {

                // Energy required if we jump from step (n-i) to step n
                int x = fact(n - i, k, heights, arr)
                        + abs(heights[n] - heights[n - i]);

                // Update the minimum energy among all possible jumps
                m = min(m, x);
            }
        }

        // Store and return the minimum energy required to reach step n
        return arr[n] = m;
    }

    int frogJump(vector<int>& heights, int k) {

        // DP array initialized with -1
        // -1 means the answer for that step has not been computed yet
        vector<int> arr(heights.size(), -1);

        // Find the minimum energy required to reach the last step
        return fact(heights.size() - 1, k, heights, arr);
    }
};