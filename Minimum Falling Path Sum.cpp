#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        for(int i = n - 2; i >= 0; i--)
        {
            matrix[i][0] += min(matrix[i + 1][0], matrix[i + 1][1]);
            for(int j = 1; j < n - 1; j++)
            {
                matrix[i][j] += min(matrix[i + 1][j - 1], min(matrix[i + 1][j], matrix[i + 1][j + 1]));
            }
            matrix[i][n - 1] += min(matrix[i + 1][n - 2], matrix[i + 1][n - 1]);
        }

        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};