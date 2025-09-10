#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubmat(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = mat[i][j];
                }
                else
                {
                    dp[i][j] = (mat[i][j] == 0) ? 0 : dp[i][j - 1] + 1;
                }

                int current = dp[i][j];
                for (int k = i; k >= 0; k--)
                {
                    current = min(current, dp[k][j]);
                    if (current == 0)
                    {
                        break;
                    }
                    ans += current;
                }
            }
        }

        return ans;
    }
};