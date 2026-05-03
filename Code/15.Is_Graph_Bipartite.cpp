// Bipartite Graph [ Brute Force DFS ]

// We are given a graph and we need to check whether it is bipartite or not.
// A graph is bipartite if we can color the graph using two colors such that
// no two adjacent nodes have the same color.
// First, we represent the graph using an adjacency list.
// Then, we create a color array and initialize all nodes with color 0,
// which means not colored.
// We traverse all nodes, because the graph may be disconnected.
// For each uncolored j, we start DFS and color it with color 1.
// Then we color its neighbors with opposite color (-1).
// If we ever find two adjacent nodes having the same color,
// then the graph is not bipartite.
// If we successfully color the graph with two colors, then it is bipartite.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    bool dfs(int i, vector<vector<int>>& graph, vector<int>& color) {
        
        // For each adjacency list thats why traversing that list only
        for (int j = 0; j < graph[i].size(); j++) {

            int neighbor = graph[i][j];

            // If neighbor not colored
            if (color[neighbor] == 0) {
                color[neighbor] = -color[i];

                if (dfs(neighbor, graph, color) == false) {
                    return false;
                }
            }
            
            // If neighbor has same color -> not bipartite
            else if (color[neighbor] == color[i]) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> color(n, 0);

        // Graph may be disconnected
        for (int i = 0; i < n; i++) {
            if (color[i] == 0) {
                
                color[i] = 1;
                if (dfs(i, graph, color) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution obj;

    // Example graph
    vector<vector<int>> graph = {
        {1,3},
        {0,2},
        {1,3},
        {0,2}
    };

    if (obj.isBipartite(graph)) {
        cout << "Graph is Bipartite";
    } else {
        cout << "Graph is Not Bipartite";
    }

    return 0;
}