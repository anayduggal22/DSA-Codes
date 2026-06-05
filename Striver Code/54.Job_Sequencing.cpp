// Given an 2D array Jobs of size Nx3, where Jobs[i][0] represents JobID , Jobs[i][1] represents Deadline , Jobs[i][2] represents Profit associated with that job. Each Job takes 1 unit of time to complete and only one job can be scheduled at a time.

// The profit associated with a job is earned only if it is completed by its deadline. Find the number of jobs and maximum profit.

// Input : Jobs = [ [1, 4, 20] , [2, 1, 10] , [3, 1, 40] , [4, 1, 30] ]
// Output : 2 60
// Explanation : Job with JobID 3 can be performed at time t=1 giving a profit of 40.
// Job with JobID 1 can be performed at time t=2 giving a profit of 20.
// No more jobs can be scheduled, So total Profit = 40 + 20 => 60.
// Total number of jobs completed are two, JobID 1, JobID 3.
// So answer is 2 60.

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <climits>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // Sort jobs by profit (high to low)
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[2] > b[2];
    }

    vector<int> JobScheduling(vector<vector<int>> &Jobs)
    {

        sort(Jobs.begin(), Jobs.end(), cmp);

        // Find maximum deadline
        int mx = 0;

        for (int i = 0; i < Jobs.size(); i++)
        {
            mx = max(mx, Jobs[i][1]);
        }

        // Slots for scheduling jobs
        vector<int> slot(mx + 1, -1);

        int count = 0;
        int profit = 0;

        // Process jobs by highest profit first
        for (int i = 0; i < Jobs.size(); i++)
        {

            int deadline = Jobs[i][1];

            // Find latest free slot before deadline
            for (int j = deadline; j >= 1; j--)
            {

                // Empty slot found
                if (slot[j] == -1)
                {

                    slot[j] = Jobs[i][0];

                    count++;

                    profit += Jobs[i][2];

                    break;
                }
            }
        }

        return {count, profit};
    }
};