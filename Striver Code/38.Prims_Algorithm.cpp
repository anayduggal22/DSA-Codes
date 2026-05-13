// You are given a weighted, undirected, and connected graph with V vertices numbered from 0 to V-1.
// The graph is provided in the form of an adjacency list, where each entry adj[u] contains a list of pairs [v, w], representing an edge between vertex u and vertex v with weight w.
// Find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph.

// A minimum spanning tree (MST) or minimum weight spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight.

// Input: V = 4, adj = [[0, 1, 1], [1, 2, 2], [2, 3, 3], [0, 3, 4]]
// Output: 6
// Explanation:
// Edges included in the MST:
// From node 0 → [1, 1] (weight 1)
// From node 1 → [2, 2] (weight 2)
// From node 2 → [3, 3] (weight 3)
// The total MST weight is 1 + 2 + 3 = 6.
// These edges connect all vertices (0, 1, 2, 3) with minimum cost.

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &adj)
    {

        // ---------------------------------------------------
        // STEP 1:
        // Convert edge list into adjacency list
        // ---------------------------------------------------

        vector<vector<pair<int, int>>> graph(V);

        for (int i = 0; i < adj.size(); i++)
        {
            int u = adj[i][0];
            int v = adj[i][1];
            int w = adj[i][2];

            // Undirected graph
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        // ---------------------------------------------------
        // MIN PRIORITY QUEUE
        //
        // Stores:
        // {weight, {node, parent}}
        // ---------------------------------------------------

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>>
            p;

        // Start from node 0
        p.push({0, {0, -1}});

        // Total MST weight
        int sum = 0;

        // Stores MST edges
        vector<pair<int, int>> path;

        // Visited array
        vector<int> visited(V, 0);

        // ---------------------------------------------------
        // PRIM'S ALGORITHM
        // ---------------------------------------------------

        while (!p.empty())
        {

            // Extract minimum weight edge
            int d = p.top().first;
            int n = p.top().second.first;
            int parent = p.top().second.second;

            p.pop();

            // Skip if already visited
            if (visited[n] == 1)
            {
                continue;
            }

            // Mark node visited
            visited[n] = 1;

            // Add edge weight to MST
            sum += d;

            // Store MST edge
            // Ignore starting node because parent = -1
            if (parent != -1)
            {
                path.push_back({parent, n});
            }

            // Traverse neighbours
            for (int i = 0; i < graph[n].size(); i++)
            {
                int adjNode = graph[n][i].first;
                int weight = graph[n][i].second;

                // Push only unvisited neighbours
                if (visited[adjNode] == 0)
                {
                    p.push({weight, {adjNode, n}});
                }
            }
        }

        // ---------------------------------------------------
        // PRINT MST PATH
        // ---------------------------------------------------

        cout << "Edges in MST:\n";

        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i].first
                 << " -> "
                 << path[i].second
                 << endl;
        }

        cout << "Total Weight = " << sum << endl;

        return sum;
    }
};