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

    // Function to count how many cows can be placed
    // with minimum distance = dist
    int count(vector<int>& nums, int dist) {

        int c = 1; // First cow placed at first stall
        int last = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            // If current stall is at least "dist" away
            // from previous placed cow
            if(nums[i] - last >= dist) {

                c++;
                last = nums[i];
            }
        }

        return c;
    }

    int aggressiveCows(vector<int> &nums, int k) {

        // Sorting required for greedy placement
        sort(nums.begin(), nums.end());

        // Minimum possible distance
        int low = 1;

        // Maximum possible distance
        int high = nums[nums.size() - 1] - nums[0];

        int ans = 0;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            // Count cows that can be placed
            int c = count(nums, mid);

            // If less than k cows can be placed
            // reduce distance
            if(c < k) {

                high = mid - 1;
            }

            // If k or more cows can be placed
            // try larger distance
            else if(c >= k) {

                ans = mid;
                low = mid + 1;
            }
        }

        return ans;
    }
};