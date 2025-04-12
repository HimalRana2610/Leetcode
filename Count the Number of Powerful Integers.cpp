#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long countGood(long long n, int limit)
    {
        string s = to_string(n);
        int len = s.size();
        vector<vector<vector<long long>>> dp(len + 1, vector<vector<long long>>(2, vector<long long>(2, -1)));

        function<long long(int, int, int)> dfs = [&](int pos, int tight, int started) -> long long
        {
            if(pos == len)
            {
                return 1LL;
            }
            if(dp[pos][tight][started] != -1)
            {
                return dp[pos][tight][started];
            }

            long long res = 0;
            int up = (tight ? s[pos] - '0' : 9);
            up = min(up, limit);

            for(int d = 0; d <= up; d++)
            {
                int nstarted = started || (d != 0);
                int ntight = tight;

                if(tight)
                {
                    if(d < s[pos] - '0')
                    {
                        ntight = 0;
                    }
                }
                res += dfs(pos + 1, ntight, nstarted);
            }

            dp[pos][tight][started] = res;
            return res;
        };

        return dfs(0, 1, 0);
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s)
    {
        int m = s.length();
        long long B = 1;

        for(int i = 0; i < m; i++)
        {
            B *= 10;
        }

        long long sNum = stoll(s);
        if(finish < sNum)
        {
            return 0;
        }

        long long pLow, pHigh;
        if(start <= sNum)
        {
            pLow = 0;
        }
        else
        {
            pLow = (start - sNum + B - 1) / B;
        }

        pHigh = (finish - sNum) / B;
        if(pLow > pHigh)
        {
            return 0;
        }

        long long countHigh = countGood(pHigh, limit);
        long long countLow = (pLow > 0 ? countGood(pLow - 1, limit) : 0);

        return countHigh - countLow;
    }
};