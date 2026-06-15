// Find the repeating and missing numbers

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
public:

    // Using and Hash Array O(n) Time & O(n) Space
    vector<int> findMissingRepeatingNumbers(vector<int> &nums)
    {
        vector<int> res(nums.size() + 1);
        vector<int> arr;
        int repeating, missing;

        for (int i = 0; i < nums.size(); i++)
        {
            res[nums[i]]++;
        }

        for (int i = 1; i < res.size(); i++)
        {
            if (res[i] == 2)
            {
                repeating = i;
            }
            else if (res[i] == 0)
            {
                missing = i;
            }
        }

        arr.push_back(repeating);
        arr.push_back(missing);
        return arr;
    }
};

int main()
{

    return 0;
}