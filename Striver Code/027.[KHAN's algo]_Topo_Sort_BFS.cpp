// TOPO SORT by giving adjacency list and no of vertices

#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    void bfs(vector<vector<int>> &adj, vector<int> &indegree, vector<int> &arr, queue<int> &q)
    {
        while (q.empty() == 0)
        {
            int index = q.front();
            q.pop();

            arr.push_back(index);

            for (int j = 0; j < adj[index].size(); j++)
            {
                int neigh = adj[index][j];

                indegree[neigh]--;

                if (indegree[neigh] == 0)
                {
                    q.push(neigh);
                }
            }
        }
    }

    vector<int> topoSort(int V, vector<vector<int>> &adj)
    {
        vector<int> indegree(V, 0);
        queue<int> q;

        // build indegree
        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                int neigh = adj[i][j];
                indegree[neigh]++;
            }
        }

        // push 0 indegree nodes
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> arr;

        bfs(adj, indegree, arr, q);

        return arr;
    }
};