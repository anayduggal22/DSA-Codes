// Given a Directed Acyclic Graph of N vertices from 0 to N-1 and M edges and a 2D Integer array edges, where there is a directed edge from vertex edge[i][0] to vertex edge[i][1] with a distance of edge[i][2] for all i.
// Find the shortest path from source vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex. The source vertex is assumed to be 0.

// Input: N = 4, M = 2 edge = [[0,1,2],[0,2,1]]

// Output: 0 2 1 -1

#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

// We first create the graph in adjacency list format where every node stores
// {neighbour, weight}. Then using DFS we find the topological order of the DAG.
// After getting the topo order, we process the nodes one by one from the stack
// and relax all their edges. Since in DAG the topo order guarantees that a node
// comes before its outgoing edges, we can directly find the shortest paths in
// one traversal. At the end, all unreachable nodes are marked as -1.

class Solution
{
public:
    
    // For finding the topological order
    void dfs(vector<vector<pair<int, int>>> &graph,
             vector<int> &visited,
             stack<int> &s,
             int index)
    {

        visited[index] = 1;

        // Looking at its connected components
        for (int i = 0; i < graph[index].size(); i++)
        {

            int neigh = graph[index][i].first;

            if (visited[neigh] == 0)
            {
                dfs(graph, visited, s, neigh);
            }
        }

        // After the DFS calls
        s.push(index);
    }

    
    // For finding the shortest distance
    void shortestDistance(vector<vector<pair<int, int>>> &graph,
                          vector<int> &distance,
                          stack<int> &s)
    {

        while (!s.empty())
        {

            int index = s.top();
            s.pop();

            // If node itself is unreachable, skip it
            if (distance[index] == INT_MAX)
                continue;

            for (int i = 0; i < graph[index].size(); i++)
            {

                int neigh = graph[index][i].first;
                int d = graph[index][i].second;

                // Relaxation
                if (distance[neigh] > distance[index] + d)
                {

                    distance[neigh] = distance[index] + d;
                }
            }
        }
    }

    
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {

        vector<vector<pair<int, int>>> graph(N); // Adjacency List

        // Creating graph
        for (int i = 0; i < M; i++)
        {

            int r = edges[i][0];
            int c = edges[i][1];
            int w = edges[i][2];

            graph[r].push_back({c, w});
        }

        
        // Topological Sort
        stack<int> s;
        vector<int> visited(N, 0);

        for (int i = 0; i < N; i++)
        {

            if (visited[i] == 0)
            {
                dfs(graph, visited, s, i);
            }
        }

        
        // Distance array
        vector<int> distance(N, INT_MAX);

        distance[0] = 0; // Source distance to itself is 0

        
        // Find shortest paths
        shortestDistance(graph, distance, s);

        
        // Mark unreachable nodes
        for (int i = 0; i < distance.size(); i++)
        {

            if (distance[i] == INT_MAX)
            {
                distance[i] = -1;
            }
        }

        return distance;
    }
};