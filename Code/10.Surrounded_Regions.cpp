// Surrounded Regions

// First using a DFS function, find all the boundary 'O' and mark it and its components differently [Ex: 'N'], as we don't need to change them to 'X' in the final traversal as those components have boundary cells.

// Then using nested loop, traverse to the whole 2D matrix and change all the remaining 'O' to 'X' and all 'N' to 'O

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void dfs(vector<vector<char>> &board, int row, int col)
    {

        board[row][col] = 'N';

        int r[] = {0, -1, 0, 1};
        int c[] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + r[i];
            int ncol = col + c[i];

            if (nrow >= 0 && nrow < board.size() && ncol >= 0 &&
                ncol < board[0].size() && board[nrow][ncol] == 'O')
            {
                dfs(board, nrow, ncol);
            }
        }
    }

    void solve(vector<vector<char>> &board)
    {

        // Finding boundary 'O' and changing them and their connected component to 'N'
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {

                if (i == 0 || i == board.size() - 1 
                 || j == 0 || j == board[0].size() - 1)
                {

                    if (board[i][j] == 'O')
                    {
                        dfs(board, i, j);
                    }
                }
            }
        }


        // Traversing the board again and changing 'O' to 'X' and 'N' to 'O'
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {

                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'N')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};

int main()
{
    Solution obj;

    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};

    obj.solve(board);

    cout << "Board after solving:\n";

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}