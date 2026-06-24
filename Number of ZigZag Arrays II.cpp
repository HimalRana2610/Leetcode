#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<long long>> mul(vector<vector<long long>> &a, vector<vector<long long>> &b)
    {
        int n = a.size(), m = b[0].size();
        vector<vector<long long>> ans(n, vector<long long>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < a[0].size(); k++)
            {
                long long r = a[i][k];
                if (r == 0)
                {
                    continue;
                }

                for (int j = 0; j < m; j++)
                {
                    ans[i][j] = (ans[i][j] + r * b[k][j]) % 1000000007;
                }
            }
        }

        return ans;
    }

    vector<vector<long long>> powMul(vector<vector<long long>> base, long long exp, vector<vector<long long>> ans)
    {
        while (exp > 0)
        {
            if (exp & 1)
            {
                ans = mul(ans, base);
            }

            base = mul(base, base);
            exp >>= 1;
        }

        return ans;
    }

    int zigZagArrays(int n, int l, int r)
    {
        int m = r - l + 1;
        if (n == 1)
        {
            return m;
        }

        int size = 2 * m;
        vector<vector<long long>> u(size, vector<long long>(size, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < i; j++)
            {
                u[i][j + m] = 1;
            }
            for (int j = i + 1; j < m; j++)
            {
                u[i + m][j] = 1;
            }
        }

        vector<vector<long long>> dp(1, vector<long long>(size, 1));
        dp = powMul(move(u), n - 1, move(dp));

        long long ans = 0;
        for (int i = 0; i < size; i++)
        {
            ans = (ans + dp[0][i]) % 1000000007;
        }

        return ans;
    }
};