#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSumDivThree(vector<int> &nums)
    {
        vector<int> dp(3, 0);
        for (int num : nums)
        {
            vector<int> temp(dp);
            for (int i = 0; i < 3; i++)
            {
                int newSum = temp[i] + num;
                dp[newSum % 3] = max(dp[newSum % 3], newSum);
            }
        }

        return dp[0];
    }
};