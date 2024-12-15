#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int numTilings(int n)
    {
        if(n <= 2)
        {
            return n;
        }

        vector<long long> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for(int i = 4; i <= n; i++)
        {
            dp[i] = (dp[i - 1] + dp[i - 2] + 2 * dp[i - 3]) % 1000000007;

            for(int j = 4; j <= i; j++)
            {
                dp[i] = (dp[i] + 2 * dp[i - j]) % 1000000007;
            }
        }

        return dp[n];
    }
};