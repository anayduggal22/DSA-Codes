// Given the arrival and departure times of all trains reaching a particular railway station, determine the minimum number of platforms required so that no train is kept waiting. Consider all trains arrive and depart on the same day.

// In any particular instance, the same platform cannot be used for both the departure of one train and the arrival of another train, necessitating the use of different platforms in such cases.

// Input : Arrival = [900, 940, 950, 1100, 1500, 1800] , Departure = [910, 1200, 1120, 1130, 1900, 2000]
// Output : 3
// Explanation : The first , second , fifth number train can use the platform 1.
// The third and sixth train can use the platform 2.
// The fourth train will use platform 3.
// So total we need 3 different platforms for the railway station so that no train is kept waiting.

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
    // Sort by time
    // If same time, arrival first
    static bool cmp(vector<int> &a, vector<int> &b)
    {

        if (a[0] == b[0])
        {
            return a[1] > b[1];
        }

        return a[0] < b[0];
    }

    int findPlatform(vector<int> &Arrival, vector<int> &Departure)
    {

        vector<vector<int>> timings;

        for (int i = 0; i < Arrival.size(); i++)
        {

            // Arrival increases platform count
            timings.push_back({Arrival[i], 1});

            // Departure decreases platform count
            timings.push_back({Departure[i], -1});
        }

        sort(timings.begin(), timings.end(), cmp);

        int count = 0;
        int max_count = 0;

        for (int i = 0; i < timings.size(); i++)
        {

            count += timings[i][1];

            max_count = max(max_count, count);
        }

        return max_count;
    }
};