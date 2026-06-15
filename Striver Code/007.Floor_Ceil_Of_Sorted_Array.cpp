// Floor and Ceil in Sorted Array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
public:
    vector<int> findFloor(int arr[], int n, int x)
    {
        int low = 0;
        int high = n - 1;
        int mid;
        if (x > arr[high])
        {
            return {arr[high], -1};
        }
        if (x < arr[low])
        {
            return {-1, arr[low]};
        }
        int floor;
        int ceil;
        int done = 0;
        while (low <= high)
        {
            mid = (low + high) / 2;
            
            // If found a greater, find more greater element
            if (x > arr[mid])
            {
                low = mid + 1;
            }

            // If found a smaller, find more smaller elemetnt
            else if(x < arr[mid])
            {
                high = mid - 1;
            }
            
            // If found the element, then its floor and ceil are that element
            else{
                ceil = arr[mid];
                floor = arr[mid];
                done = 1;
                break;
            }
        }

        if(!done){
            ceil = arr[low];
            floor = arr[high];
        }

        return {floor, ceil};
    }
};

int main()
{

    return 0;
}