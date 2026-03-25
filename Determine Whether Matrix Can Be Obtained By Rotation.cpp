#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate_90(vector<vector<int>> &mat)
    {
        int n = mat.size();
        vector<vector<int>> rotated(n, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                rotated[i][j] = mat[n - j - 1][i];
            }
        }

        mat = rotated;
    }

    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        for (int i = 0; i < 4; i++)
        {
            rotate_90(mat);
            if (mat == target)
            {
                return true;
            }
        }

        return false;
    }
};