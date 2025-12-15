#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, string &s, vector<vector<int>> &adj, vector<vector<int>> &next, vector<int> &prefix, vector<vector<int>> &arr, vector<int> &dp)
    {
        int n = s.size();
        if (i >= n)
        {
            return 0;
        }

        if (dp[i] != -1)
        {
            return dp[i];
        }

        int ans = 0;
        for (int j = 0; j < 26; j++)
        {
            if (adj[s[i] - 'a'][j] == 0)
            {
                continue;
            }

            int idx = upper_bound(next[j].begin(), next[j].end(), i) - next[j].begin();
            if (idx == next[j].size())
            {
                continue;
            }

            int x = next[j][idx], cost = prefix[x] - ((i > 0) ? prefix[i - 1] : 0), cnt = arr[j][x] - ((i > 0) ? arr[j][i - 1] : 0), p = int(char(j + 'a'));
            cost -= p * cnt;
            ans = max(ans, cost + solve(x, s, adj, next, prefix, arr, dp));
        }

        return dp[i] = ans;
    }

    int maxScore(string &s, vector<vector<char>> &jumps)
    {
        int n = s.length(), m = jumps.size();
        if (n == 1)
        {
            return 0;
        }

        vector<vector<int>> adj(26, vector<int>(26, 0));
        for (int i = 0; i < 26; i++)
        {
            adj[i][i] = 1;
        }

        for (int i = 0; i < m; i++)
        {
            adj[jumps[i][0] - 'a'][jumps[i][1] - 'a'] = 1;
        }

        vector<int> prefix(n, 0);
        for (int i = 0; i < n; i++)
        {
            prefix[i] = int(s[i]);
            if (i > 0)
            {
                prefix[i] += prefix[i - 1];
            }
        }

        vector<vector<int>> arr(26, vector<int>(n, 0));
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < 26; i++)
            {
                if (j > 0)
                {
                    arr[i][j] += arr[i][j - 1];
                }
                if ((s[j] - 'a') == i)
                {
                    arr[i][j]++;
                }
            }
        }

        vector<vector<int>> next(26, vector<int>());
        for (int i = 0; i < n; i++)
        {
            next[s[i] - 'a'].push_back(i);
        }

        vector<int> dp(n, -1);
        return solve(0, s, adj, next, prefix, arr, dp);
    }
};