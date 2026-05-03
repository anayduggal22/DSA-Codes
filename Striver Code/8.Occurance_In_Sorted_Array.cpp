// Count Occurrences in Sorted Array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
public:
    int Occurrence(vector<int> &arr, int n, int k)
    {
        int first = -1;
        int last = -1;
        // Done if the element does not exist.
        int low = 0;
        int high = n - 1;
        int mid;

        // Done to find the FIRST Occurence
        while (low <= high)
        {
            mid = low + (high - low) / 2;

            // Look at Left
            if (k < arr[mid])
            {
                high = mid - 1;
            }

            // Look at right
            else if (k > arr[mid])
            {
                low = mid + 1;
            }

            // If the element is found, its first occurence will be on the LEFT side
            else if (k == arr[mid])
            {
                first = mid;
                high = mid - 1;
            }
        }

        // If The element DOES NOT exist
        if (first == -1)
        {
            return -1;
        }

        // Done to find the LAST Occurence
        low = 0;
        high = n - 1;
        while (low <= high)
        {
            mid = low + (high - low) / 2;

            // Look at Left
            if (k < arr[mid])
            {
                high = mid - 1;
            }

            // Look at right
            else if (k > arr[mid])
            {
                low = mid + 1;
            }

            // If the element is found, its last occurence will be on the RIGHT side
            else if (k == arr[mid])
            {
                last = mid;
                low = mid + 1;
            }
        }

        int total = last - first + 1;
        return total;
    }
};

int main()
{

    return 0;
}