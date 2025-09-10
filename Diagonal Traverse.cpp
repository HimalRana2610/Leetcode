#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> diagonals;

        for (int i = 0; i < n; i++)
        {
            vector<int> current;
            for (int j = 0, k = i; j < m && k >= 0; j++, k--)
            {
                current.push_back(mat[j][k]);
            }
            diagonals.push_back(current);
        }

        for (int i = 1; i < m; i++)
        {
            vector<int> current;
            for (int j = i, k = n - 1; j < m && k >= 0; j++, k--)
            {
                current.push_back(mat[j][k]);
            }
            diagonals.push_back(current);
        }

        vector<int> ans;
        for (int i = 0; i < diagonals.size(); i++)
        {
            if (i % 2 == 0)
            {
                for (int j = diagonals[i].size() - 1; j >= 0; j--)
                {
                    ans.push_back(diagonals[i][j]);
                }
            }
            else
            {
                for (int j = 0; j < diagonals[i].size(); j++)
                {
                    ans.push_back(diagonals[i][j]);
                }
            }
        }

        return ans;
    }
};