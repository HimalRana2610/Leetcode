#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSets(int n, int k)
    {
        vector<int> dp(n), prefix(n + 1);
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
            prefix[i + 1] = (prefix[i] + dp[i]) % 1000000007;
        }

        for (int i = 1; i <= k; i++)
        {
            dp[0] = 0;
            for (int j = 1; j < n; j++)
            {
                dp[j] = (dp[j - 1] + prefix[j]) % 1000000007;
            }
            for (int j = 0; j < n; j++)
            {
                prefix[j + 1] = (prefix[j] + dp[j]) % 1000000007;
            }
        }

        return dp[n - 1];
    }
};