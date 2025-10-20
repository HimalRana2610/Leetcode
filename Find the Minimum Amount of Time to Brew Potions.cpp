#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minTime(vector<int> &skill, vector<int> &mana)
    {
        int n = skill.size(), m = mana.size();
        vector<long long> dp(n);

        for (int i = 0; i < m; i++)
        {
            long long current = 0;
            for (int j = 0; j < n; j++)
            {
                current = max(current, dp[j]) + skill[j] * mana[i];
            }

            dp[n - 1] = current;
            for (int j = n - 2; j >= 0; j--)
            {
                dp[j] = dp[j + 1] - skill[j + 1] * mana[i];
            }
        }

        return dp[n - 1];
    }
};