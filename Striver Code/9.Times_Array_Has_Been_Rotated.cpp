// Find out how many times the array has been rotated

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
public:
    int findRotationCount(vector<int> &arr) {
        int low = 0;
        int high = arr.size() -1;
        int mid;

        // Finding the start of the sorted array, i.e the min term
        while(low < high){ // IMP, not low <= high
            mid = low + (high - low)/2;

            // If mid is small than high, then more smaller term in left side
            if(arr[mid] < arr[high]){
                high = mid;
            }
            
            // If mid is greater than high, then more smaller term is on right side
            else if(arr[mid] > arr[high]){
                low = mid +1;
            }
        }

        // This is the index where the min term OR the starting term is placed, so it will also be how many rotations it took to get this element there.
        return low;

    }
};

int main()
{

    return 0;
}