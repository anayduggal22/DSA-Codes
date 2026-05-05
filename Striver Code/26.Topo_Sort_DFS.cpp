// TOPO SORT by giving adjacency list and no of vertices

#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &adj, vector<int>& visited, stack<int>& s, int index)
    {

        visited[index] = 1;

        for (int i = 0; i < adj[index].size(); i++)
        {
            int neighboor = adj[index][i];

            if (visited[neighboor] == 0)
            {
                dfs(adj, visited, s, neighboor);
            }
        }

        s.push(index);
    }

    vector<int> topoSort(int V, vector<vector<int>> &adj)
    {
        vector<int> visited(V, 0);
        stack<int> s;

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                dfs(adj, visited, s, i);
            }
        }

        vector<int> arr;

        while (s.empty() == 0)
        {
            arr.push_back(s.top());
            s.pop();
        }

        return arr;
    }
};