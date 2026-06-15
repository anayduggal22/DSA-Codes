// Given an integer M and an undirected graph with N vertices (zero indexed) and E edges. The goal is to determine whether the graph can be coloured with a maximum of M colors so that no two of its adjacent vertices have the same colour applied to them.

// In this context, colouring a graph refers to giving each vertex a different colour. If the colouring of vertices is possible then return true, otherwise return false.

// Input : N = 4 , M = 3 , E = 5 , Edges = [ (0, 1) , (1, 2) , (2, 3) , (3, 0) , (0, 2) ]
// Output : true
// Explanation : Consider the three colors to be red, green, blue.
// We can color the vertex 0 with red, vertex 1 with blue, vertex 2 with green, vertex 3 with blue.

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <climits>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool valid(int node, vector<vector<int>> &graph, vector<int> &color, int col)
    {

        // Check all adjacent vertices
        for (int i = 0; i < graph.size(); i++)
        {

            if (graph[node][i] == 1 && color[i] == col)
            {
                return false;
            }
        }

        return true;
    }

    bool solve(int node, vector<vector<int>> &graph,
               vector<int> &color, int m)
    {

        // Base Case
        if (node == graph.size())
        {
            return true;
        }

        // Try all possible colors
        for (int col = 1; col <= m; col++)
        {

            if (valid(node, graph, color, col) == true)
            {

                color[node] = col;

                if (solve(node + 1, graph, color, m) == true)
                {
                    return true;
                }

                // BackTracking and removing color
                color[node] = 0;
            }
        }

        return false;
    }

    bool graphColoring(int n, vector<pair<int, int>> &edges, int m)
    {

        // Create adjacency matrix
        vector<vector<int>> graph(n, vector<int>(n, 0));

        for (auto edge : edges)
        {
            int u = edge.first;
            int v = edge.second;

            graph[u][v] = 1;
            graph[v][u] = 1;
        }

        // Stores color assigned to each vertex
        vector<int> color(n, 0);

        return solve(0, graph, color, m);
    }
};