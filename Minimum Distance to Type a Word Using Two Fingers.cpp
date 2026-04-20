#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDistance(string word)
    {
        int n = word.size();
        vector<vector<int>> dp(n, vector<int>(26, INT_MAX >> 1));
        fill(dp[0].begin(), dp[0].end(), 0);

        for (int i = 1; i < n; ++i)
        {
            int dist = abs((word[i - 1] - 'A') / 6 - (word[i] - 'A') / 6) + abs((word[i - 1] - 'A') % 6 - (word[i] - 'A') % 6);
            for (int j = 0; j < 26; ++j)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + dist);
                if (word[i - 1] - 'A' == j)
                {
                    for (int k = 0; k < 26; ++k)
                    {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs((k / 6) - (word[i] - 'A') / 6) + abs((k % 6) - (word[i] - 'A') % 6));
                    }
                }
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};