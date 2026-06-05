// You have n items; the i-th item has value val[i] and weight wt[i].

// A knapsack can carry at most capacity units of weight.

// You may take any fraction of an item (i.e. split items).

// Return the maximum total value that can be placed in the knapsack, rounded to exactly 6 decimal places.

// Input: val = [60,100,120], wt = [10,20,30], capacity = 50
// Output: 240.000000
// Explanation:
//  • Take item 0 (w=10, v=60)
//  • Take item 1 (w=20, v=100)
//  • Take 2⁄3 of item 2 (w=20, v=80)
// Total value = 60 + 100 + 80 = 240

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
    // Sort by value/weight ratio in descending order
    static bool cmp(vector<long long> &a, vector<long long> &b)
    {

        double r1 = (double)a[0] / a[1];
        double r2 = (double)b[0] / b[1];

        return r1 > r2;
    }

    double fractionalKnapsack(vector<long long> &val,
                              vector<long long> &wt,
                              long long capacity)
    {

        vector<vector<long long>> arr;

        // Store {value, weight}
        for (int i = 0; i < val.size(); i++)
        {
            arr.push_back({val[i], wt[i]});
        }

        // Highest ratio first
        sort(arr.begin(), arr.end(), cmp);

        double sum = 0;

        for (int i = 0; i < arr.size(); i++)
        {

            // If whole item cannot fit
            if (capacity < arr[i][1])
            {

                // Take fraction of item
                sum += ((double)arr[i][0] * capacity) / arr[i][1];
                break;
            }

            else
            {

                // Take whole item
                capacity -= arr[i][1];
                sum += arr[i][0];
            }
        }

        return sum;
    }
};