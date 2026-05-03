// Number of Islands

// Just Use the Depth-First Search Algorithem with condition of going only Up-Down-Right-Left.
// At the same time in the main function, check if there is an island which is not visited using nested loops, then make it visited and do dfs on it.
// Do this till the whole grid is traversed.

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void dfs(int m, int n, vector<vector<char>> &grid,
             vector<vector<int>> &visited)
    {
        int row = m;
        int col = n;

        // For Up-Down-Left-Right Checking
        int r[] = {0, 1, 0, -1};
        int c[] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++)
        {
            int fr = row + r[i];
            int fc = col + c[i];

            // Checking if Up-Down-Left-Right exist and are part of
            // island or not..
            if (fr >= 0 && fr < grid.size() 
             && fc >= 0 && fc < grid[0].size() 
             && grid[fr][fc] == '1' && visited[fr][fc] == 0)
            {

                // Marking it as visited and continuing the dfs search
                visited[fr][fc] = 1;
                dfs(fr, fc, grid, visited);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {

        // IMP initialization
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));

        int islands = 0;

        for (int m = 0; m < grid.size(); m++)
        {
            for (int n = 0; n < grid[0].size(); n++)
            {
                // For all different islands
                if (grid[m][n] == '1' && visited[m][n] == 0)
                {
                    islands++;
                    visited[m][n] = 1;
                    dfs(m, n, grid, visited);
                }
            }
        }

        return islands;
    }
};

int main()
{
    Solution obj;

    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    cout << obj.numIslands(grid);

    return 0;
}