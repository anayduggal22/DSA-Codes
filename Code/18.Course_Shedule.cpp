// Course Schedule Problem (Cycle Detection in Directed Graph)

// First, we represent the graph using an adjacency list (implemented using a linked list).
// Each course points to the courses that depend on it.
// Then, we use Depth-First Search (DFS) to detect a cycle in the directed graph.
// We maintain a visited array with 3 states:
// 0 = Not visited
// 1 = Visiting (currently in recursion stack)
// 2 = Visited (DFS completed)
// During DFS, if we reach a node that is already in the Visiting state,
// it means we found a cycle, so it is not possible to finish all courses.
// If no cycle is found after checking all nodes, then all courses can be completed.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // DFS function to detect cycle
    bool dfs(int i, vector<vector<int>>& adj, vector<int>& vis) {

        vis[i] = 1; // visiting

        // check all possible neighbors
        for (int neighbor = 0; neighbor < adj.size(); neighbor++) {

            if (adj[i][neighbor] == 1) {

                if (vis[neighbor] == 0) {
                    if (dfs(neighbor, adj, vis) == true) {
                        return true;
                    }
                }

                else if (vis[neighbor] == 1) { // In its visiting state
                    return true; // cycle detected
                }
            }
        }

        vis[i] = 2; // visited
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // Adjacency matrix
        vector<vector<int>> adj(numCourses, vector<int>(numCourses, 0));

        // Build graph
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1]; // prerequisite
            int v = prerequisites[i][0]; // course

            adj[u][v] = 1;
        }

        // Visited array
        vector<int> vis(numCourses, 0);

        // Check cycle for each course
        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (dfs(i, adj, vis) == true) {
                    return false; // cycle exists
                }
            }
        }

        return true; // no cycle
    }
};

int main() {
    Solution obj;

    int numCourses = 4;

    vector<vector<int>> prerequisites = {
        {1,0},
        {2,0},
        {3,1},
        {3,2}
    };

    if (obj.canFinish(numCourses, prerequisites)) {
        cout << "All courses can be finished";
    } else {
        cout << "Cycle detected, cannot finish courses";
    }

    return 0;
}