#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long power(long long base, int exp)
    {
        long long ans = 1;
        while (exp)
        {
            if (exp & 1)
            {
                ans = (ans * base) % 1000000007;
            }

            base = (base * base) % 1000000007;
            exp >>= 1;
        }

        return ans;
    }

    int countGoodArrays(int n, int m, int k)
    {
        vector<long long> fact(100000), fact_inv(100000);
        fact[0] = 1;

        for (int i = 1; i < 100000; i++)
        {
            fact[i] = (fact[i - 1] * i) % 1000000007;
        }

        fact_inv[99999] = power(fact[99999], 1000000005);
        for (int i = 99999; i > 0; i--)
        {
            fact_inv[i - 1] = (fact_inv[i] * i) % 1000000007;
        }

        return (((((((fact[n - 1] * fact_inv[k]) % 1000000007) * fact_inv[n - k - 1]) % 1000000007) * m) % 1000000007) * power(m - 1, n - k - 1)) % 1000000007;
    }
};