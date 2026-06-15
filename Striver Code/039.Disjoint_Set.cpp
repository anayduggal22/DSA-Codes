// You are given n nodes numbered from 1 to n.
// You are also given connections between nodes.
// Each connection joins two nodes into the same component.
// Return the number of connected components.

// Input: n = 5, edges = {{1,2}, {2,3}, {4,5}}
// Output: 2
// Explanation:
// Component 1 -> {1,2,3}
// Component 2 -> {4,5}
// So total connected components = 2

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Solution
{
public:
    // Finding Ultimate Parent of Child
    int find(vector<int> &parent, int child)
    {

        // If Parent of Child is itself, then it is Ultimate Parent
        if (parent[child] == child)
        {
            return child;
        }

        // Path Compression
        return parent[child] = find(parent, parent[child]);
    }

    void union_find(vector<int> &rank, vector<int> &parent, int r, int c)
    {

        // Finding Ultimate Parent
        int p_r = find(parent, r);
        int p_c = find(parent, c);

        // If both have same Ultimate Parent,
        // then they already belong to same component
        if (p_r == p_c)
        {
            return;
        }

        // Union By Rank
        else
        {

            // Connecting Smaller Rank Tree to Bigger Rank Tree
            if (rank[p_r] > rank[p_c])
            {
                parent[p_c] = p_r;
            }

            else if (rank[p_c] > rank[p_r])
            {
                parent[p_r] = p_c;
            }

            // If both have same Rank,
            // make anyone parent and increase its rank
            else
            {
                parent[p_c] = p_r;
                rank[p_r]++;
            }
        }
    }

    int countComponents(int n, vector<vector<int>> &edges)
    {

        // 1-based indexing, thats why (n+1)
        vector<int> rank(n + 1, 0);
        vector<int> parent(n + 1);

        // Initially every node is parent of itself
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }

        // Connecting Nodes
        for (int i = 0; i < edges.size(); i++)
        {

            int r = edges[i][0];
            int c = edges[i][1];

            union_find(rank, parent, r, c);
        }

        int components = 0;

        // Counting Number of Components
        for (int i = 1; i <= n; i++)
        {

            // If Ultimate Parent is itself,
            // then it is leader of one component
            if (find(parent, i) == i)
            {
                components++;
            }
        }

        return components;
    }
};