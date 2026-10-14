#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> resultArray(vector<int> &nums, int k)
    {
        vector<long long> dp(k), ans(k);
        for (int i = 0; i < nums.size(); i++)
        {
            vector<long long> new_dp(k);
            new_dp[nums[i] % k]++;

            for (int j = 0; j < k; j++)
            {
                new_dp[(long long)j * nums[i] % k] += dp[j];
            }

            dp = move(new_dp);
            for (int j = 0; j < k; j++)
            {
                ans[j] += dp[j];
            }
        }

        return ans;
    }
};