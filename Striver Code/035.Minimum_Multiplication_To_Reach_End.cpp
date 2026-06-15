// Given start, end, and an array arr of n numbers. At each step, the start is multiplied by any number in the array and then a mod operation with 100000 is done to get the new start.

// Find the minimum steps in which the end can be achieved starting from the start. If it is not possible to reach the end, then return -1.

// Input: arr = [2, 5, 7], start = 3, end = 30
// Output: 2
// Explanation:
// Step 1: 3*2 = 6 % 100000 = 6
// Step 2: 6*5 = 30 % 100000 = 30

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    int minimumMultiplications(vector<int> &arr,
                               int start, int end)
    {

        // Edge Case
        if (start == end)
        {
            return 0;
        }

        // Storing minimum steps to reach every number
        vector<int> steps(100000, INT_MAX);

        queue<pair<int, int>> q;
        // {steps,node}

        q.push({0, start});

        // Starting node takes 0 steps to reach
        steps[start] = 0;

        while (!q.empty())
        {

            int s = q.front().first;
            int node = q.front().second;
            q.pop();

            // Looking at all possible multiplications
            for (int i = 0; i < arr.size(); i++)
            {

                // Modulo operation after multiplication
                int temp = (node * arr[i]) % 100000;

                // If a shorter path is found
                if (s + 1 < steps[temp])
                {

                    steps[temp] = s + 1;

                    // End reached
                    if (temp == end)
                    {
                        return steps[temp];
                    }

                    q.push({steps[temp], temp});
                }
            }
        }

        // End cannot be reached
        return -1;
    }
};