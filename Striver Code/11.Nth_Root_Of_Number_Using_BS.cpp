// Nth Root of a Number using Binary Search

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
public:

    // IMPORTANT
    // Binary O(n * log m) Solution
    int nthRoot(int n, int m)
    {
        int low = 1;
        int high = m;
        int mid;
        long long int x = 1;

        while (low <= high)
        {
            mid = low + (high - low) / 2;
            
            // To caclculate mid^n
            x = 1;
            for (int i = 1; i <= n; i++)
            {
                x *= mid;

                // IF mid^n > m, then go to left to find a smaller number
                if (x > m)
                {
                    high = mid - 1;
                    break;
                }
            }
            
            // IF mid^n < m, then go to right to find a greater number
            if (x < m)
            {
                low = mid + 1;
            }

            // IF mid^n == m, then return the mid.
            else if (x == m)
            {
                return mid;
            }
        }

        // If no mid found, then return -1
        return -1;
    }
};

int main()
{

    return 0;
}