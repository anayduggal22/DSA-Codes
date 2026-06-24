// A ninja has planned a n-day training schedule. Each day he has to perform one of three activities - running, stealth training, or fighting practice. The same activity cannot be done on two consecutive days and the ninja earns a specific number of merit points, based on the activity and the given day.

// Given a n x 3-sized matrix, where matrix[i][0], matrix[i][1], and matrix[i][2], represent the merit points associated with running, stealth and fighting practice, on the (i+1)th day respectively. Return the maximum possible merit points that the ninja can earn.

// Input: matrix = [[10, 40, 70], [20, 50, 80], [30, 60,90]]
// Output: 210
// Explanation:
// Day 1: fighting practice = 70
// Day 2: stealth training = 50
// Day 3: fighting practice = 90
// Total = 70 + 50 + 90 = 210
// This gives the optimal points.

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

        int tabulation(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // dp[day][last]
        // last = 0,1,2 means last activity performed
        // last = 3 means no activity restriction
        vector<vector<int>> dp(n, vector<int>(4, 0));

        // Base case for day 0
        dp[0][0] = max(matrix[0][1], matrix[0][2]);
        dp[0][1] = max(matrix[0][0], matrix[0][2]);
        dp[0][2] = max(matrix[0][0], matrix[0][1]);
        dp[0][3] = max({matrix[0][0], matrix[0][1], matrix[0][2]});

        // Fill the DP table
        for (int day = 1; day < n; day++) {

            for (int last = 0; last < 4; last++) {

                dp[day][last] = 0;

                // Try all activities
                for (int task = 0; task < 3; task++) {

                    // Skip if same as previous day's activity
                    if (task != last) {

                        int points = matrix[day][task] +
                                     dp[day - 1][task];

                        dp[day][last] =
                            max(dp[day][last], points);
                    }
                }
            }
        }

        // No restriction on the last day
        return dp[n - 1][3];
    }


    // Function to find the maximum merit points up to day 'n'
    // 'last' stores the activity performed on the previous day
    int fact(int n, int last, vector<vector<int>>& matrix, vector<vector<int>>& dp) {

        // Base case: first day
        if (n == 0) {

            int maxi = 0;

            // Choose the maximum activity except the last performed one
            for (int i = 0; i <= 2; i++) {
                if (i != last) {
                    maxi = max(maxi, matrix[n][i]);
                }
            }

            return maxi;
        }

        // If already computed, return the stored value
        if (dp[n][last] != -1) {
            return dp[n][last];
        }

        int maxi = 0;

        // Try all three activities for the current day
        for (int i = 0; i <= 2; i++) {

            // Cannot perform the same activity as the previous day
            if (i != last) {

                // Current day's points + maximum points from previous days
                int points = matrix[n][i] + fact(n - 1, i, matrix, dp);

                // Update the maximum points
                maxi = max(maxi, points);
            }
        }

        // Store and return the result
        return dp[n][last] = maxi;
    }

    int ninjaTraining(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // DP table:
        // Rows -> days
        // Columns -> last activity (0,1,2,3)
        // 3 means no activity was performed previously
        vector<vector<int>> dp(n, vector<int>(4, -1));

        // Initially, there is no previous activity
        return fact(n - 1, 3, matrix, dp);
    }
};