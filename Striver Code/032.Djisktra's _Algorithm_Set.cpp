// Given a weighted, undirected graph of V vertices, numbered from 0 to V-1, and an 2D vector/array which represents the edges:

// Each entry in edges[i] is of the form [u, v, weight], where:

// u, v → represents the vertex having undirected edge between them
// weight → the weight of the edge between u and v

// Given a source node S. Find the shortest distance of all the vertex from the source vertex S. Return a list of integers denoting shortest distance between each node and source vertex S. If a vertex is not reachable from source then its distance will be 109.

// Input: V = 2, edges = [[0,1,9]] , S=0
// Output: [0, 9]

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <set>

// Complexities:

// Time: O(E log V)
// Space: O(V + E)

using namespace std;

class Solution
{
public:
    // Dijkstra traversal using set
    void shortest_path(vector<vector<pair<int, int>>> &graph, vector<int> &distance, set<pair<int, int>> &s)
    {

        // Traverse until all reachable nodes processed
        while (!s.empty())
        {

            // First element in set always has minimum distance
            auto x = *(s.begin());

            int d = x.first;
            int index = x.second;

            // Remove current node from set
            s.erase(x);

            // Traverse all neighbours of current node
            for (int i = 0; i < graph[index].size(); i++)
            {

                int neigh = graph[index][i].first;
                int weight = graph[index][i].second;

                // Relaxation condition
                // If new distance is smaller than previous distance
                if (d + weight < distance[neigh])
                {

                    // If neighbour already exists in set with older distance
                    // remove it first
                    if (distance[neigh] != INT_MAX)
                    {

                        s.erase({distance[neigh], neigh});
                    }

                    // Update shortest distance
                    distance[neigh] = d + weight;

                    // Push updated distance and node into set
                    s.insert({distance[neigh], neigh});
                    // {Distance, node}
                }
            }
        }
    }

    vector<int> dijkstra(int V, vector<vector<int>> edges, int S)
    {

        // Adjacency list
        vector<vector<pair<int, int>>> graph(V);

        // Making undirected weighted graph
        for (int i = 0; i < edges.size(); i++)
        {

            int r = edges[i][0];
            int c = edges[i][1];
            int w = edges[i][2];

            graph[r].push_back({c, w}); // r -> c
            graph[c].push_back({r, w}); // c -> r
        }

        // Distance array initialized with infinity
        vector<int> distance(V, INT_MAX);

        // Source node distance is always 0
        distance[S] = 0;

        // Set works like min heap here
        set<pair<int, int>> s;

        // Push source node into set
        s.insert({0, S});
        // {Distance, node}

        // Start Dijkstra traversal
        shortest_path(graph, distance, s);

        return distance;
    }
};