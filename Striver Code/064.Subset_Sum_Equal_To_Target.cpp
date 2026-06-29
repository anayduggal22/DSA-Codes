// Given an array arr of n integers and an integer target,
// determine if there is a subset of the given array with a sum equal to the given target.
//
// Input: arr = [1, 2, 7, 3], target = 6
// Output: True
// Explanation: There is a subset (1, 2, 3) with sum 6.

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // ---------------- Memoization ----------------
    bool fact(int index, int target, vector<vector<int>> &dp, vector<int> &arr)
    {
        // If target becomes 0, we have found a valid subset
        if (target == 0)
        {
            return true;
        }

        // Base case: only first element left
        if (index == 0)
        {
            return (arr[0] == target);
        }

        // Return already computed result
        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }

        // Option 1: Do not take current element
        bool nottake = fact(index - 1, target, dp, arr);

        // Option 2: Take current element (only if it does not exceed target)
        bool take = false;

        if (target >= arr[index])
        {
            take = fact(index - 1, target - arr[index], dp, arr);
        }

        // Store and return answer
        return dp[index][target] = (nottake || take);
    }

    // ---------------- Tabulation (Space Optimized) ----------------
    bool tabularization(int index, int target, vector<int> &arr)
    {
        // prev[j] = Can we make sum j using previous rows?
        vector<int> prev(target + 1, false);

        // Target 0 can always be achieved by taking no elements
        prev[0] = true;

        // If first element is within range, mark it
        if (arr[0] <= target)
        {
            prev[arr[0]] = true;
        }

        // Process remaining elements
        for (int i = 1; i <= index; i++)
        {
            // curr[j] = Can we make sum j using elements till index i?
            vector<int> curr(target + 1, false);

            // Sum 0 is always achievable
            curr[0] = true;

            for (int j = 1; j <= target; j++)
            {
                // Do not take current element
                bool nottake = prev[j];

                // Take current element if possible
                bool take = false;

                if (j >= arr[i])
                {
                    take = prev[j - arr[i]];
                }

                // Store answer for current state
                curr[j] = take || nottake;
            }

            // Move current row to previous row
            prev = curr;
        }

        // Final answer: Can we make the target sum?
        return prev[target];
    }

    bool isSubsetSum(vector<int> arr, int target)
    {
        int index = arr.size() - 1;

        // DP table for memoization
        vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));

        // Memoization answer
        return fact(index, target, dp, arr);

        // To use tabulation instead:
        // return tabularization(index, target, arr);
    }
};

int main()
{
    Solution obj;

    vector<int> arr = {1, 2, 7, 3};
    int target = 6;

    cout << obj.isSubsetSum(arr, target);

    return 0;
}