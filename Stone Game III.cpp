#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        int n = stoneValue.size();
        vector<int> dp = {0, 0, 0, 0};

        for (int i = n - 1; i >= 0; i--)
        {
            int j = i & 3;
            dp[j] = stoneValue[i] - dp[(i + 1) & 3];

            if (i + 2 <= n)
            {
                dp[j] = max(dp[j], stoneValue[i] + stoneValue[i + 1] - dp[(i + 2) & 3]);
            }
            if (i + 3 <= n)
            {
                dp[j] = max(dp[j], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[(i + 3) & 3]);
            }
        }

        vector<string> ans = {"Bob", "Tie", "Alice"};
        return ans[(dp[0] > 0) - (dp[0] < 0) + 1];
    }
};