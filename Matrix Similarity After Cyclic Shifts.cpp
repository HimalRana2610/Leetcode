#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool areSimilar(vector<vector<int>> &mat, int k)
    {
        int m = mat.size(), n = mat[0].size();
        k = k % n;

        vector<vector<int>> shifted = mat;
        for (int i = 0; i < m; i++)
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j < n; j++)
                {
                    shifted[i][j] = mat[i][(j + k) % n];
                }
            }
            else
            {
                for (int j = 0; j < n; j++)
                {
                    shifted[i][j] = mat[i][(j - k + n) % n];
                }
            }
        }

        return shifted == mat;
    }
};