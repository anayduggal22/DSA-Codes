// Length of the longest subarray with zero Sum

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class solution
{
public:
    // BRUTE FORCE O(n²)
    int solve(vector<int> &a)
    {
        int sum = 0;
        int longest_subarray = 0;
        for (int i = 0; i < a.size(); i++)
        {
            sum = 0;
            for (int j = i; j < a.size(); j++)
            {
                sum += a[j];
                if (sum == 0)
                {
                    longest_subarray = max(j - i + 1, longest_subarray);
                }
            }
        }
        return longest_subarray;
    }


    // PREFIX SUM O(n)
    int solve(vector<int> &a)
    {
        unordered_map<int, int> h; // Hashmap
        int p = 0; // Prefix Sum
        int longest_subarray = 0; // Longest Subarray

        for (int i = 0; i < a.size(); i++)
        {
            p += a[i];
            //If the prefix sum is Zero
            if (p == 0)
            {
                longest_subarray = max(longest_subarray,i+1);
            }

            // If You have seen this prefix sum before, then this prefix sum - that prefix sum would be zero.
            if (h.find(p) != h.end())
            {
                longest_subarray = max(longest_subarray, i - h[p]);
            }

            // Else just store the key being prefix sum, and the value being the index.
            else
            {
                h[p] = i;
            }
        }

        return longest_subarray;
    }
};

int main()
{

    return 0;
}