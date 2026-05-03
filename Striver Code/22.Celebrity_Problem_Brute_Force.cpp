// Celebrity Problem
// Brute Force O(n^2)

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>> &M)
    {
        // To check for followers and followings
        int following, follower;

        for (int i = 0; i < M.size(); i++)
        {
            following = 0;
            follower = 0;

            for (int j = 0; j < M[0].size(); j++)
            {
                // If i follows j
                if (M[i][j] == 1)
                {
                    following++;
                }

                // If j follows i
                if (M[j][i] == 1)
                {
                    follower++;
                }

            }

            // Celebrity is one who follows no one and has all followers except itself
            if (following == 0 && follower == M.size() - 1)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
}