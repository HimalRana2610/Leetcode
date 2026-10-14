#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        int n = s.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
        dp[n][0] = true;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= n; j++)
            {
                bool valid = false;
                if (s[i] == '*')
                {
                    valid |= dp[i + 1][j + 1];
                    if (j > 0)
                    {
                        valid |= dp[i + 1][j - 1];
                    }
                    valid |= dp[i + 1][j];
                }
                else
                {
                    if (s[i] == '(')
                    {
                        valid |= dp[i + 1][j + 1];
                    }
                    else if (j > 0)
                    {
                        valid |= dp[i + 1][j - 1];
                    }
                }
                dp[i][j] = valid;
            }
        }

        return dp[0][0];
    }
};