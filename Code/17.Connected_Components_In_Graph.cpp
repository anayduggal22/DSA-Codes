// Number of Connected Components in a Grid

// We use Depth-First Search (DFS) to explore all cells that belong to the same component.
// From each cell, we move in 4 directions: Up, Down, Left, Right.
// We traverse the grid, and whenever we find a cell with value 1 that is not visited,
// we start a DFS and mark the whole connected component as visited.
// Each DFS call represents one connected component.

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void dfs(int m, int n, vector<vector<int>> &grid,
             vector<vector<int>> &visited)
    {
        int row = m;
        int col = n;

        // Directions: Left, Down, Right, Up
        int r[] = {0, 1, 0, -1};
        int c[] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++)
        {
            int fr = row + r[i];
            int fc = col + c[i];

            // Check boundaries and whether the cell is part of component
            if (fr >= 0 && fr < grid.size() &&
                fc >= 0 && fc < grid[0].size() &&
                grid[fr][fc] == 1 && visited[fr][fc] == 0)
            {
                visited[fr][fc] = 1;
                dfs(fr, fc, grid, visited);
            }
        }
    }


    int countComponents(vector<vector<int>> &grid)
    {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));

        int components = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1 && visited[i][j] == 0)
                {
                    components++;
                    visited[i][j] = 1;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return components;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}};

    cout << "Number of Connected Components: "
         << obj.countComponents(grid);

    return 0;
}