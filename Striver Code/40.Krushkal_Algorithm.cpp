// You are given a weighted, undirected, and connected graph
// with V vertices numbered from 0 to V-1.
// The graph is given as:
// [u, v, w]
// where:
// u = source node
// v = destination node
// w = weight of edge
// Find the sum of weights of edges
// in the Minimum Spanning Tree (MST).
// MST:
// - Connects all vertices
// - Contains no cycles
// - Has minimum possible total weight

// Input: V = 4, adj = {{0,1,1}, {1,2,2}, {2,3,3}, {0,3,4}}
// Output: 6
// Explanation:
// Edges included in MST:
// 0 -> 1 (weight 1)
// 1 -> 2 (weight 2)
// 2 -> 3 (weight 3)
// Total Weight = 1 + 2 + 3 = 6

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <climits>
#include <algorithm>

using namespace std;

class Solution
{
public:

    // Finding Ultimate Parent of Child
    int find(vector<int> &parent, int child)
    {

        // If Parent of Child is itself,
        // then it is Ultimate Parent
        if (parent[child] == child)
        {
            return child;
        }

        // Path Compression
        return parent[child] = find(parent, parent[child]);
    }

    int union_find(vector<int> &rank, vector<int> &parent, int r, int c)
    {

        // Finding Ultimate Parent
        int p_r = find(parent, r);
        int p_c = find(parent, c);

        // If both belong to same component,
        // then adding edge will form cycle
        if (p_r == p_c)
        {
            return -1;
        }

        // Union By Rank
        else
        {

            // Connecting Smaller Rank Tree
            // to Bigger Rank Tree
            if (rank[p_r] > rank[p_c])
            {
                parent[p_c] = p_r;
            }

            else if (rank[p_c] > rank[p_r])
            {
                parent[p_r] = p_c;
            }

            // If both have same rank,
            // make anyone parent and increase rank
            else
            {
                parent[p_c] = p_r;
                rank[p_r]++;
            }
        }

        return 0;
    }

    // Sorting Edges According to Weight
    void sort_weight(vector<vector<int>> &adj)
    {

        for (int i = 0; i < adj.size() - 1; i++)
        {
            for (int j = 0; j < adj.size() - 1 - i; j++)
            {

                // Comparing Edge Weights
                if (adj[j][2] > adj[j + 1][2])
                {
                    swap(adj[j], adj[j + 1]);
                }
            }
        }
    }

    int spanningTree(int V, vector<vector<int>> &adj)
    {

        // Sorting Edges in Increasing Weight
        sort_weight(adj);

        // 0-based indexing, thats why size = V
        vector<int> rank(V, 0);
        vector<int> parent(V);

        // Initially every node is parent of itself
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }

        int mst = 0;

        // Counting Number of Edges Added in MST
        int edges = 0;

        // Traversing All Edges
        for (int i = 0; i < adj.size(); i++)
        {

            int r = adj[i][0];
            int c = adj[i][1];
            int w = adj[i][2];

            // If edge forms cycle, skip it
            if (union_find(rank, parent, r, c) == -1)
            {
                continue;
            }

            // Adding Weight in MST
            mst += w;

            // One Edge Added in MST
            edges++;

            // MST always contains V-1 edges
            if (edges == V - 1)
            {
                break;
            }
        }

        return mst;
    }
};