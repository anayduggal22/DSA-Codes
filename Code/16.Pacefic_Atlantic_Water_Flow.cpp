// Pacific Atlantic Water Flow [ DFS ]

// Create two visited matrices, one for Pacific Ocean and one for Atlantic Ocean.
// Pacific Ocean touches the top row and left column.
// Atlantic Ocean touches the bottom row and right column.
// First, run DFS from all cells on the top row and left column and mark all cells
// reachable from Pacific Ocean in pacific visited matrix.
// Then, run DFS from all cells on the bottom row and right column and mark all cells
// reachable from Atlantic Ocean in atlantic visited matrix.
// During DFS, we only move to neighboring cells if the neighbor height is
// greater than or equal to the current cell height (because water can flow
// from higher to lower, so we reverse the flow).
// At the end, traverse the whole grid and find cells which are marked visited
// in both pacific and atlantic matrices. Those cells can flow to both oceans.

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &heights, vector<vector<int>> &visited)
    {

        visited[row][col] = 1;

        int r[] = {0, -1, 0, 1};
        int c[] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + r[i];
            int ncol = col + c[i];

            if (nrow >= 0 && nrow < heights.size() &&
                ncol >= 0 && ncol < heights[0].size() &&
                visited[nrow][ncol] == 0 &&
                heights[nrow][ncol] >= heights[row][col])
            {

                dfs(nrow, ncol, heights, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {

        int m = heights.size(); 
        int n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        // Pacific Ocean (top row and left column)
        for (int i = 0; i < m; i++)
        {
            dfs(i, 0, heights, pacific);
        }

        for (int j = 0; j < n; j++)
        {
            dfs(0, j, heights, pacific);
        }


        // Atlantic Ocean (bottom row and right column)
        for (int i = 0; i < m; i++)
        {
            dfs(i, n - 1, heights, atlantic);
        }

        for (int j = 0; j < n; j++)
        {
            dfs(m - 1, j, heights, atlantic);
        }

        // Find cells reachable to both oceans
        vector<vector<int>> result;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] == 1 && atlantic[i][j] == 1)
                {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}};

    vector<vector<int>> ans = obj.pacificAtlantic(heights);

    cout << "Cells that can flow to both Pacific and Atlantic:\n";

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }

    return 0;
}