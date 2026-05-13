// Given a weighted and directed graph of V vertices and E edges. An edge is represented as [ai, bi, wi], meaning there is a directed edge from ai to bi having weight wi. Find the shortest distance of all the vertices from the source vertex S. If a vertex can't be reached from the S then mark the distance as 109.
// If the graph contains a negative cycle then return -1 in a list.

// Input : V = 6, Edges = [[3, 2, 6], [5, 3, 1], [0, 1, 5], [1, 5, -3], [1, 2, -2], [3, 4, -2], [2, 4, 3]], S = 0
// Output: 0 5 3 3 1 2
// Explanation:
// For node 1, shortest path is 0->1 (distance=5).
// For node 2, shortest path is 0->1->2 (distance=3)
// For node 3, shortest path is 0->1->5->3 (distance=3)
// For node 4, shortest path is 0->1->5->3->4 (distance=1)
// For node 5, shortest path is 0->1->5 (distance=2)

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Solution
{
public:
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {

        // Store shortest distance of every node from source
        // Initialize all distances as INF (1e8 means unreachable)
        vector<int> distance(V, 1e8);

        // Distance of source from itself is always 0
        distance[S] = 0;

        // ---------------------------------------------------
        // STEP 1: Relax all edges V-1 times
        // ---------------------------------------------------
        // Why V-1 times?
        // Because the longest possible shortest path
        // in a graph can contain at most V-1 edges.
        // After V-1 relaxations, all shortest paths are fixed.

        for (int i = 0; i < V - 1; i++)
        {

            // Traverse all edges
            for (int j = 0; j < edges.size(); j++)
            {

                // Edge: r -> c with weight w
                int r = edges[j][0];
                int c = edges[j][1];
                int w = edges[j][2];

                // If source node itself is unreachable,
                // then we cannot relax this edge
                if (distance[r] == 1e8)
                {
                    continue;
                }

                // Relaxation:
                // If going through node r gives
                // a shorter path to c, then update it
                if (distance[c] > distance[r] + w)
                {
                    distance[c] = distance[r] + w;
                }
            }
        }

        // ---------------------------------------------------
        // STEP 2: Detect Negative Weight Cycle
        // ---------------------------------------------------
        // Try relaxing edges one more time.
        //
        // If distance still decreases,
        // then a negative cycle exists.
        //
        // Why?
        // Because shortest paths should already be fixed
        // after V-1 iterations.

        for (int j = 0; j < edges.size(); j++)
        {

            int r = edges[j][0];
            int c = edges[j][1];
            int w = edges[j][2];

            // Ignore unreachable nodes
            if (distance[r] == 1e8)
            {
                continue;
            }

            // Still able to relax -> negative cycle exists
            if (distance[c] > distance[r] + w)
            {
                return {-1};
            }
        }

        // Return final shortest distances
        return distance;
    }
};