#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int idealArrays(int n, int maxValue)
    {
        vector<int> sieve(10010);
        for(int i = 2; i < 10010; i++)
        {
            if(sieve[i] == 0)
            {
                for(int j = i; j < 10010; j += i)
                {
                    sieve[j] = i;
                }
            }
        }

        vector<vector<int>> primes(10010);
        for(int i = 2; i < 10010; i++)
        {
            int x = i;
            while(x > 1)
            {
                int p = sieve[x], cnt = 0;
                while(x % p == 0)
                {
                    x /= p;
                    cnt++;
                }
                primes[i].push_back(cnt);
            }
        }

        vector<vector<int>> dp(10025, vector<int>(16));
        dp[0][0] = 1;

        for(int i = 1; i < 10025; i++)
        {
            dp[i][0] = 1;
            for(int j = 1; j <= min(i, 15); j++)
            {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 1000000007;
            }
        }

        long long ans = 0;
        for(int i = 1; i <= maxValue; i++)
        {
            long long mul = 1;
            for (int p : primes[i])
            {
                mul = mul * dp[n + p - 1][p] % 1000000007;
            }
            ans = (ans + mul) % 1000000007;
        }

        return ans;
    }
};