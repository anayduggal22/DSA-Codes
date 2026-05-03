// Kadane's Algorithm : Maximum Subarray Sum in an Array

#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
    // BRUTE FORCE O(n²)
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return nums[0];
        }
        int i = 0;
        int j;
        int sum;
        int max_sum = nums[0];
        while (i < nums.size())
        {
            j = i;
            sum = 0;
            while (j < nums.size())
            {
                sum += nums[j];
                if (max_sum < sum)
                {
                    max_sum = sum;
                }
                j++;
            }
            i++;
        }
        return max_sum;
    }

    // Kadane's Algorithm O(n)
    // 1.Keep adding elements to a running sum.
    // 2.Track the maximum sum seen so far.
    // 3.If running sum becomes negative → discard it (set to 0).
    // 4.Continue till end.
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int max_sum = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            sum = max(nums[i], sum + nums[i]);
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};

int main()
{

    return 0;
}