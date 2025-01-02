#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int numWays(vector<string>& words, string target)
    {
        int l = target.length(), m = words.size(), n = words[0].length();
        vector<vector<int>> cnt(n, vector<int>(26, 0));

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cnt[j][words[i][j] - 'a']++;
            }
        }

        vector<int> dp(l + 1, 0);
        dp[0] = 1;

        for(int i = 0; i < n; i++)
        {
            for(int j = l - 1; j >= 0; j--)
            {
                dp[j + 1] += (int)((long long)dp[j] * cnt[i][target[j] - 'a'] % 1000000007);
                dp[j + 1] %= 1000000007;
            }
        }

        return dp[l];
    }
};