#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1)
                {
                    dp[i + 1][j + 1] = min({dp[i][j], dp[i][j + 1], dp[i + 1][j]}) + 1;
                    ans += dp[i + 1][j + 1];
                }
            }
        }

        return ans;
    }
};