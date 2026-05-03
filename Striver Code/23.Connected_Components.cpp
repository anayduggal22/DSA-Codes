// Connected Components

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    void bfs(vector<vector<int>> &edges, vector<int> &visited, int node, int size, queue<int> &q)
    {

        while (q.empty() == 0)
        {
            int temp = q.front();
            q.pop();
            for (int i = 0; i < size; i++)
            {
                if (edges[temp][i] == 1 && visited[i] == 0)
                {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }
    int countComponents(int V, vector<vector<int>> &edges)
    {
        vector<int> visited(V);
        queue<int> q;

        int number_of_connected_components = 0;

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
                bfs(edges, visited, i, V, q);
                number_of_connected_components++;
            }
        }

        return number_of_connected_components;
    }
};

int main()
{

    return 0;
}