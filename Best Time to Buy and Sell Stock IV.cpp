#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maxProfit(int k, vector<int>& prices)
    {
        int n = prices.size();
        if(k >= n / 2)
        {
            int ans = 0;
            for(int i = 1; i < n; i++)
            {
                if(prices[i] > prices[i - 1])
                {
                    ans += prices[i] - prices[i - 1];
                }
            }
            return ans;
        }

        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        for(int j = 1; j <= k; j++)
        {
            int prev = -prices[0];
            for(int i = 1; i < n; i++)
            {
                dp[i][j] = max(dp[i - 1][j], prices[i] + prev);
                prev = max(prev, dp[i][j - 1] - prices[i]);
            }
        }

        return dp[n - 1][k];
    }
};