#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int n = strs.size(), m = strs[0].size(), ans = 1;
        vector<int> dp(m, 1);

        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < j; i++)
            {
                bool extend = true;
                for (int k = 0; k < n; k++)
                {
                    if (strs[k][i] > strs[k][j])
                    {
                        extend = false;
                        break;
                    }
                }

                if (extend)
                {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }

            ans = max(ans, dp[j]);
        }

        return m - ans;
    }
};