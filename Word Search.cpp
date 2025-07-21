#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(vector<vector<char>> &board, int x, int y, string current, string word, vector<vector<bool>> &visited)
    {
        if (current == word)
        {
            return true;
        }

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dirs[i].first, ny = y + dirs[i].second;
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && board[nx][ny] == word[current.length()] && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                if (solve(board, nx, ny, current + board[nx][ny], word, visited))
                {
                    return true;
                }
                visited[nx][ny] = false;
            }
        }

        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    visited[i][j] = true;
                    if (solve(board, i, j, string(1, board[i][j]), word, visited))
                    {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }

        return false;
    }
};