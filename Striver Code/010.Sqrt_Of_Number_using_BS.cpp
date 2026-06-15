// Finding Sqrt of a number using Binary Search

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
public:
    // Linear O(n) solution
    int mySqrt(int x)
    {
        if (x == 0 || x == 1)
        {
            return x;
        }
        int sqrt = 1;
        ;
        for (int i = 1; i <= x / 2; i++)
        {

            // Done to prevent overflow
            if (i == x / i)
            {
                sqrt = i;
                break;
            }

            // Done to prevent overflow
            else if (i > x / i)
            {
                sqrt = i - 1;
                break;
            }
        }
        return sqrt;
    }

    // Binary Search O(log n) solution
    int mySqrt(int x)
    {
        if (x == 0 || x == 1)
        {
            return x;
        }

        int low = 1;
        int high = x;
        int mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;

            // If mid^2 < x, then go right
            if (mid < x / mid)
            {
                low = mid + 1;
            }

            // If mid^2 > x, then go left
            else if (mid > x / mid)
            {
                high = mid - 1;
            }

            // If mid^2 == x, then return mid
            else if (mid == x / mid)
            {
                return mid;
            }
        }


        // Else return the floor of sqrt(x)
        return low - 1;
    }
};

int main()
{

    return 0;
}