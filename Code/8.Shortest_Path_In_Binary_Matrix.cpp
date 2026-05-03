// Shortest Path in Binary Matrix

// Start a bfs function from (0,0) and add coordinates to the queue which are 0 and connected and also not previously visited, do this till queue is empty, inside this loop, run the pushing from 0 to size of the queue at that time, that is for each level, between these loops, increment your lenght variable, if at any point you reach (n-1,n-1), return the length.

// After both the loops have been traversed, that is you were unable to reach the destination, return -1.

#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int bfs(vector<vector<int>> &grid, vector<vector<int>> &visited)
    {
        int length = 1;

        vector<pair<int,int>> q;
        q.push_back({0, 0});

        // Acting like front of queue
        int front = 0;

        while (front < q.size()) // Meaning while q is not empty
        {
            // For BFS on each level
            int size = q.size() - front;

            for (int k = 0; k < size; k++)
            {
                // Poping front row anc col
                int row = q[front].first;
                int col = q[front].second;
                front++;

                // Base Case if we have reached bottom right
                if (row == grid.size() - 1 && col == grid.size() - 1)
                {
                    return length;
                }

                // To check all neighbours
                for (int i = -1; i <= 1; i++)
                {
                    for (int j = -1; j <= 1; j++)
                    {
                       
                        int r = row + i;
                        int c = col + j;

                        if (r >= 0 && r < grid.size() &&
                            c >= 0 && c < grid.size() &&
                            grid[r][c] == 0 && visited[r][c] == 0)
                        {
                            q.push_back({r, c});
                            visited[r][c] = 1;
                        }
                    }
                }
            }
            // Btw while and for loop to increment length at each level
            length++;
        }

        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0] == 1)
        {
            return -1;
        }

        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));

        visited[0][0] = 1;

        return bfs(grid, visited);
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> grid = {
        {0, 1, 0},
        {0, 0, 0},
        {1, 0, 0}};

    cout << "Shortest Path Length: "
         << obj.shortestPathBinaryMatrix(grid);

    return 0;
}