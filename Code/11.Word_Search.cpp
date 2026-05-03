// Word Search [ DFS ]

// Create a visited matrix and using nested loop, traverse the board till you find the first character of the word in the board, then mark it visited and do dfs on it, also take the input of dfs and if the input is 1, return true, else unvisit that board and look for first char in rest of the board, if the word is not on the board, then after the nested loop, return false.

// In the dfs function which returns integer, and takes input as board, visited matrix, the row and col of first char of word, the word itself, and the index of word that we have to check now, check on adjacent sides of the row and col, to find the word char at given index, if found, first mark it visited, then call dfs function with index incremented, also store the dfs function output, if it is 1, return true, else if it is not, unvisit that coordinate, the base case of the dfs recursive function is when index is equal to the length of the word, at which return true.
// At the end of the function, just return false.

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int dfs(vector<vector<char>> &board, vector<vector<int>> &visited, int row, int col, string word, int l)
    {

        // Base Case
        if (l == word.length())
        {
            return 1;
        }

        int r[] = {0, -1, 0, 1};
        int c[] = {-1, 0, 1, 0};
        int nrow, ncol;

        for (int i = 0; i < 4; i++)
        {
            nrow = row + r[i];
            ncol = col + c[i];

            if (nrow >= 0 && nrow < board.size() 
            && ncol >= 0 && ncol < board[0].size() 
            && board[nrow][ncol] == word[l] && visited[nrow][ncol] == 0)
            {

                visited[nrow][ncol] = 1;
                int d = dfs(board, visited, nrow, ncol, word, l + 1);

                if (d == 1)
                {
                    // Again letter found in the sequence
                    return 1;
                }
                else
                {
                    // NOT found
                    visited[nrow][ncol] = 0;
                }
            }
        }

        return -1;
    }

    bool exist(vector<vector<char>> &board, string word)
    {

        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0] && visited[i][j] == 0)
                {
                    visited[i][j] = 1;

                    int a = dfs(board, visited, i, j, word, 1);

                    if (a == 1)
                    {
                        // Word Found
                        return true;
                    }
                    else
                    {
                        // Word Not Found
                        visited[i][j] = 0;
                    }
                }
            }
        }
        
        // When loop terminated, so return false
        return false;
    }
};

int main()
{
    Solution obj;

    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";

    if (obj.exist(board, word))
    {
        cout << "Word exists in board";
    }
    else
    {
        cout << "Word does not exist in board";
    }

    return 0;
}