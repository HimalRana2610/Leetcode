#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_valid(vector<string> &board, int row, int col)
    {
        for (int i = row; i >= 0; i--)
        {
            if (board[i][col] == 'Q')
            {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        return true;
    }

    void solve(vector<string> &board, int row, vector<vector<string>> &ans)
    {
        int n = board.size();
        if (row == n)
        {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (is_valid(board, row, i))
            {
                board[row][i] = 'Q';
                solve(board, row + 1, ans);
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        solve(board, 0, ans);
        return ans;
    }
};