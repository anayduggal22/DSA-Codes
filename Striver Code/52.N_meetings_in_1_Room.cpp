// Given one meeting room and N meetings represented by two arrays, start and end, where start[i] represents the start time of the ith meeting and end[i] represents the end time of the ith meeting, determine the maximum number of meetings that can be accommodated in the meeting room if only one meeting can be held at a time.

// Input : Start = [1, 3, 0, 5, 8, 5] , End = [2, 4, 6, 7, 9, 9]
// Output : 4
// Explanation : The meetings that can be accommodated in meeting room are (1,2) , (3,4) , (5,7) , (8,9).

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
    // Sort by meeting ending time
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }

    int maxMeetings(vector<int> &start, vector<int> &end)
    {

        vector<vector<int>> intervals;

        // Store meetings as {start, end}
        for (int i = 0; i < start.size(); i++)
        {
            intervals.push_back({start[i], end[i]});
        }

        // Earliest ending meeting first
        sort(intervals.begin(), intervals.end(), cmp);

        // First meeting is always selected
        int meetings = 1;

        int ending = intervals[0][1];

        // Check remaining meetings
        for (int i = 1; i < intervals.size(); i++)
        {

            // Non-overlapping meeting
            if (intervals[i][0] > ending)
            {

                meetings++;

                // Update current ending time
                ending = intervals[i][1];
            }
        }

        return meetings;
    }
};