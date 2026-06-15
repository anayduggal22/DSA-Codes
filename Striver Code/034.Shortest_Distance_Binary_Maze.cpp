// Given an n x m matrix grid where each cell contains either 0 or 1, determine the shortest distance between a source cell and a destination cell. You can move to an adjacent cell (up, down, left, or right) if that adjacent cell has a value of 1. The path can only be created out of cells containing 1. If the destination cell is not reachable from the source cell, return -1.

// Input: grid = [[1, 1, 1, 1],[1, 1, 0, 1],[1, 1, 1, 1],[1, 1, 0, 0],[1, 0, 0, 1]], source = [0, 1], destination = [2, 2]
// Output: 3
// Explanation: The shortest path from (0, 1) to (2, 2) is:
// Move down to (1, 1)
// Move down to (2, 1)
// Move right to (2, 2)
// Thus, the shortest distance is 3

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <set>

    using namespace std;

class Solution
{
public:
    // BFS function to traverse level by level
    int bfs(vector<vector<int>> &grid, vector<vector<int>> &distance, pair<int, int> source, pair<int, int> destination)
    {

        queue<pair<int, int>> q;

        // Push source node in queue to start BFS
        q.push({source.first, source.second});

        while (!q.empty())
        {

            // Current node coordinates
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // If destination reached, return shortest distance
            if (row == destination.first && col == destination.second)
            {
                return distance[row][col];
            }

            // Left, Up, Right, Down movement
            int r[] = {0, -1, 0, 1};
            int c[] = {-1, 0, 1, 0};

            // Traverse all 4 directions
            for (int i = 0; i < 4; i++)
            {

                int nrow = row + r[i];
                int ncol = col + c[i];

                // Boundary check
                // Cell should contain 1
                // And new distance should be smaller than previous distance
                if (nrow >= 0 && nrow < grid.size() &&
                    ncol >= 0 && ncol < grid[0].size() &&
                    grid[nrow][ncol] == 1 &&
                    distance[nrow][ncol] > distance[row][col] + 1)
                {

                    // Push neighbour node into queue
                    q.push({nrow, ncol});

                    // Update shortest distance for neighbour
                    distance[nrow][ncol] = distance[row][col] + 1;
                }
            }
        }

        // Destination not reachable
        return -1;
    }

    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {

        // Distance matrix initialized with INT_MAX
        vector<vector<int>> distance(grid.size(), vector<int>(grid[0].size(), INT_MAX));

        // Source distance is always 0
        distance[source.first][source.second] = 0;

        // If source or destination is blocked, path impossible
        if (grid[source.first][source.second] == 0 ||
            grid[destination.first][destination.second] == 0)
        {
            return -1;
        }

        // Start BFS traversal
        return bfs(grid, distance, source, destination);
    }
};
