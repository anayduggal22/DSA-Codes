// Given a grid of dimensions n x n. A rat is placed at coordinates (0, 0) and wants to reach at coordinates (n-1, n-1).

// Find all possible paths that rat can take to travel from (0, 0) to (n-1, n-1). The directions in which rat can move are 'U' (up) , 'D' (down) , 'L' (left) , 'R' (right).

// The value 0 in grid denotes that the cell is blocked and rat cannot use that cell for travelling, whereas value 1 represents that rat can travel through the cell. If the cell (0, 0) has 0 value, then mouse cannot move to any other cell.

// Note :

// In a path no cell can be visited more than once.
// If there is no possible path then return empty vector.

// Input : n = 4 , grid = [ [1, 0, 0, 0] , [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1] ]
// Output : [ "DDRDRR" , "DRDDRR" ]
// Explanation : The rat has two different path to reach (3, 3).
// The first path is (0, 0) => (1, 0) => (2, 0) => (2, 1) => (3, 1) => (3, 2) => (3, 3).
// The second path is (0,0) => (1,0) => (1,1) => (2,1) => (3,1) => (3,2) => (3,3).

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
    bool valid(vector<vector<int>> &grid, vector<vector<int>> &visited,
               int row, int col)
    {

        // Out of bounds
        if (row < 0 || col < 0 ||
            row >= grid.size() || col >= grid.size())
        {
            return false;
        }

        // Blocked cell
        if (grid[row][col] == 0)
        {
            return false;
        }

        // Already visited cell
        if (visited[row][col] == 1)
        {
            return false;
        }

        return true;
    }

    void solve(vector<vector<int>> &grid, vector<vector<int>> &visited,
               vector<string> &ans, string path, int row, int col)
    {

        // Base Case
        // Rat has reached the destination
        if (row == grid.size() - 1 && col == grid.size() - 1)
        {
            ans.push_back(path);
            return;
        }

        // Mark current cell as visited
        visited[row][col] = 1;

        // Move Down
        if (valid(grid, visited, row + 1, col) == true)
        {
            solve(grid, visited, ans, path + 'D', row + 1, col);
        }

        // Move Left
        if (valid(grid, visited, row, col - 1) == true)
        {
            solve(grid, visited, ans, path + 'L', row, col - 1);
        }

        // Move Right
        if (valid(grid, visited, row, col + 1) == true)
        {
            solve(grid, visited, ans, path + 'R', row, col + 1);
        }

        // Move Up
        if (valid(grid, visited, row - 1, col) == true)
        {
            solve(grid, visited, ans, path + 'U', row - 1, col);
        }

        // BackTracking and unvisiting the cell
        // So that it can be used in another path
        visited[row][col] = 0;
    }

    vector<string> findPath(vector<vector<int>> &grid)
    {

        vector<string> ans;

        // If starting cell is blocked
        if (grid[0][0] == 0)
        {
            return ans;
        }

        int n = grid.size();

        // Visited matrix to avoid revisiting cells
        vector<vector<int>> visited(n, vector<int>(n, 0));

        string path = "";

        // Start from (0,0)
        solve(grid, visited, ans, path, 0, 0);

        return ans;
    }
};