#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        vector<int> dp(high + 1, 0);
        dp[0] = 1;

        for(int i = 0; i <= high; i++)
        {
            if(dp[i] > 0)
            {
                if(i + zero <= high)
                {
                    dp[i + zero] = (dp[i + zero] + dp[i]) % 1000000007;
                }
                if(i + one <= high)
                {
                    dp[i + one] = (dp[i + one] + dp[i]) % 1000000007;
                }
            }
        }

        int ans = 0;
        for(int i = low; i <= high; i++)
        {
            ans = (ans + dp[i]) % 1000000007;
        }

        return ans;
    }
};