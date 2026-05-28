#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <climits>
#include <math.h>

using namespace std;

class Solution
{
public:

    // Function to count how many painters are needed
    // if one painter can paint at most "weight" board length
    int count(vector<int> &C, int weight)
    {
        int c = 1; // Initially first painter
        int last = C[0]; // First board assigned

        for (int i = 1; i < C.size(); i++)
        {

            // If current board can be assigned
            // to current painter
            if (last + C[i] <= weight)
            {
                last += C[i];
            }

            // Otherwise assign to next painter
            else
            {
                c++;
                last = C[i];
            }
        }

        return c;
    }

    int paint(int A, int B, vector<int> &C)
    {

        int n = 0;
        int sum = 0;

        for (int i = 0; i < C.size(); i++)
        {

            // Minimum answer can never be smaller
            // than maximum board length
            n = max(n, C[i]);

            // Maximum answer can be sum of all boards
            sum += C[i];
        }

        // Binary search on board length
        int low = n;
        int high = sum;

        long long ans = 0;

        while (low <= high)
        {

            // Mid board length assigned as maximum limit
            int mid = low + (high - low) / 2;

            // Count painters needed for this limit
            int c = count(C, mid);

            // If painters required are less than or equal to A
            // then this answer is possible
            if (c <= A)
            {
                ans = mid;

                // Try finding smaller answer
                high = mid - 1;
            }

            // If more painters are needed
            // increase maximum board limit
            else
            {
                low = mid + 1;
            }
        }

        // Multiply by time taken per unit board
        return (ans * B) % 10000003;
    }
};