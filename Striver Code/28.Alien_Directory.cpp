// Given a sorted dictionary of an alien language having N words and K starting alphabets of a standard dictionary. Find the order of characters in the alien language.
// There may be multiple valid orders for a particular test case, thus you may return any valid order as a string. The output will be True if the order returned by the function is correct, else False denoting an incorrect order. If the given arrangement of words is inconsistent with any possible letter ordering, return an empty string "".

// Input: N = 5, K = 4, dict = ["baa","abcd","abca","cab","cad"]

// Output: b d a c 

#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;


class Solution
{
public:
    // Here Compare two consecutive words and find the first difference, then create a graph of k x k size and mark down graph[w1 diff][w2 diff] = 1, do this N-1 times, now you will have a directed acyclic graph, then using DFS/BFS topological sort find the order, and that will be the ans.

    void dfs(vector<vector<int>> &grid, vector<int> &visited, stack<int> &s, int index)
    {

        visited[index] = 1;

        // Looking at its connected components
        for (int i = 0; i < grid[index].size(); i++)
        {

            int neigh = grid[index][i];

            if (visited[neigh] == 0)
            {
                dfs(grid, visited, s, neigh);
            }
        }

        // After the DFS calls
        s.push(index);
    }

    string findOrder(string dict[], int N, int K)
    {

        vector<vector<int>> grid(K); // Adjacency List

        for (int i = 0; i < N - 1; i++)
        {

            string s1 = dict[i];
            string s2 = dict[i + 1];

            int j = 0;

            while (j < s1.length() && j < s2.length())
            {

                
                if (s1[j] != s2[j])
                {
                    int r = s1[j] - 'a';
                    int c = s2[j] - 'a';
                    
                    grid[r].push_back(c);

                    break; // First Difference
                }
                
                j++;
            }

            // Nothing found
            if (j == s2.length() && s1.length() > s2.length())
            {
                return "";
            }


        }
        


        stack<int> s;
        vector<int> visited(K, 0);

        for (int i = 0; i < grid.size(); i++)
        {

            if (visited[i] == 0)
            {
                dfs(grid, visited, s, i);
            }
        }

        string ans = "";

        while (!s.empty())
        {
            ans += (s.top() + 'a'); // Convert to char and add it to the string

            s.pop();
        }

        return ans;
    }
};
