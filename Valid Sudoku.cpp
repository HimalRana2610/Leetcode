#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            unordered_set<char> s;
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (s.find(board[i][j]) != s.end())
                    {
                        return false;
                    }
                    s.insert(board[i][j]);
                }
            }
        }

        for (int j = 0; j < 9; j++)
        {
            unordered_set<char> s;
            for (int i = 0; i < 9; i++)
            {
                if (board[i][j] != '.')
                {
                    if (s.find(board[i][j]) != s.end())
                    {
                        return false;
                    }
                    s.insert(board[i][j]);
                }
            }
        }

        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                unordered_set<char> s;
                for (int k = 0; k < 9; k++)
                {
                    if (board[i + k / 3][j + k % 3] != '.')
                    {
                        if (s.find(board[i + k / 3][j + k % 3]) != s.end())
                        {
                            return false;
                        }
                        s.insert(board[i + k / 3][j + k % 3]);
                    }
                }
            }
        }

        return true;
    }
};