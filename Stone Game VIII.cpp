#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int stoneGameVIII(vector<int> &stones)
    {
        int n = stones.size();
        vector<int> prefix;
        partial_sum(stones.begin(), stones.end(), back_inserter(prefix));

        vector<int> dp(n);
        dp[n - 1] = prefix[n - 1];

        for (int i = n - 2; i >= 1; i--)
        {
            dp[i] = max(dp[i + 1], prefix[i] - dp[i + 1]);
        }

        return dp[1];
    }
};