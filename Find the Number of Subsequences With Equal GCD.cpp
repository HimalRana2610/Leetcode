#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subsequencePairCount(vector<int> &nums)
    {
        int n = nums.size(), m = *max_element(nums.begin(), nums.end());
        vector<vector<int>> dp(m + 1, vector<int>(m + 1));
        dp[0][0] = 1;

        for (int i = 0; i < n; i++)
        {
            vector<vector<int>> new_dp(m + 1, vector<int>(m + 1));
            for (int j = 0; j <= m; j++)
            {
                int g1 = __gcd(j, nums[i]);
                for (int k = 0; k <= m; k++)
                {
                    if (dp[j][k] == 0)
                    {
                        continue;
                    }

                    int g2 = __gcd(k, nums[i]);
                    new_dp[j][k] = (new_dp[j][k] + dp[j][k]) % 1000000007;
                    new_dp[g1][k] = (new_dp[g1][k] + dp[j][k]) % 1000000007;
                    new_dp[j][g2] = (new_dp[j][g2] + dp[j][k]) % 1000000007;
                }
            }

            dp.swap(new_dp);
        }

        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            ans = (ans + dp[i][i]) % 1000000007;
        }

        return ans;
    }
};