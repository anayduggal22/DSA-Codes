// Implement Lower Bound

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
public:
    // Using Binary Search O(log n)
    int lowerBound(vector<int>& arr, int n, int x)
    {
        int low = 0;
        int high = n - 1;
        int mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (arr[mid] >= x)
            {
                high = mid - 1;
            }
            else if (arr[mid] < x)
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main()
{

    return 0;
}