// Celebrity Problem
// Optimal by using STACK, O(n)

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>> &M)
    {

        stack<int> s;

        // Push all the indices in the stack
        for (int i = 0; i < M.size(); i++)
        {
            s.push(i);
        }

        // Do this till stack has 1 element
        while (s.size() != 1)
        {
            // Pop first index
            int a = s.top();
            s.pop();

            // After popping first index, if stack becomes empty
            // , then no celebrity is there, so return -1
            if (s.empty())
            {
                return -1;
            }

            // Else pop the second index
            int b = s.top();
            s.pop();

            // If a follows b, then a cannot be celebrity but b can be
            // , so push b
            if (M[a][b] == 1)
            {
                s.push(b);
            }

            // If b follows a, then b cannot be celebrity but a can be
            // , so push a
            else
            {
                s.push(a);
            }
        }

        // Now pop the last element of the STACK
        int candidate = s.top();
        s.pop();

        // Check if this candidate follows no one and
        // Every elment appart follows the candidate apart from itself
        for (int i = 0; i < M.size(); i++)
        {
            if (i == candidate)
            {
                continue;
            }
            if (M[candidate][i] == 1 || M[i][candidate] == 0)
            {
                return -1;
            }
        }

        return candidate;
    }
};

int main()
{

    return 0;
}