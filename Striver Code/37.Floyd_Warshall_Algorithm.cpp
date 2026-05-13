// Given a graph of V vertices numbered from 0 to V-1. Find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n x n. Matrix[i][j] denotes the weight of the edge from i to j. If matrix[i][j]=-1, it means there is no edge from i to j.

// Input: matrix = [[0, 2, -1, -1],[1, 0, 3, -1],[-1, -1, 0, 1],[3, 5, 4, 0]]
// Output: [[0, 2, 5, 6], [1, 0, 3, 4], [4, 6, 0, 1], [3, 5, 4, 0]] 
// Explanation: 
// matrix[0][0] is storing the distance from vertex 0 to vertex 0, the distance from vertex 0 to vertex 1 is 2 and so on.

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Solution {
public:

    void shortestDistance(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // ---------------------------------------------------
        // STEP 1:
        // Convert -1 to INF
        //
        // Because:
        // -1 means no edge exists
        // Floyd Warshall works better using INF
        // ---------------------------------------------------

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(matrix[i][j] == -1) {
                    matrix[i][j] = 1e8;
                }
            }
        }

        // ---------------------------------------------------
        // STEP 2:
        // Floyd Warshall Algorithm
        // ---------------------------------------------------
        //
        // Try every node as an intermediate node (via)
        //
        // Check:
        // Is path:
        // i -> via -> j
        //
        // shorter than:
        // i -> j
        //
        // ---------------------------------------------------

        for(int via = 0; via < n; via++) {

            for(int i = 0; i < n; i++) {

                for(int j = 0; j < n; j++) {

                    // If either path does not exist,
                    // skip to avoid overflow
                    if(matrix[i][via] == 1e8 ||
                       matrix[via][j] == 1e8) {
                        continue;
                    }

                    // Relaxation
                    if(matrix[i][j] >
                       matrix[i][via] + matrix[via][j]) {

                        matrix[i][j] =
                        matrix[i][via] + matrix[via][j];
                    }
                }
            }
        }

        // ---------------------------------------------------
        // STEP 3:
        // Convert INF back to -1
        // ---------------------------------------------------

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(matrix[i][j] == 1e8) {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};