#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long inverse(long long x)
    {
        long long ans = 1, exp = 1000000005;
        while (exp > 0)
        {
            if (exp & 1)
            {
                ans = (ans * x) % 1000000007;
            }
            x = (x * x) % 1000000007;
            exp >>= 1;
        }

        return ans;
    }

    vector<int> productQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> powers;
        for (int i = 30; i >= 0; i--)
        {
            while (n >= (1 << i))
            {
                powers.push_back(1 << i);
                n -= (1 << i);
            }
        }

        sort(powers.begin(), powers.end());

        vector<int> prefix(powers.size() + 1, 1);
        for (int i = 0; i < powers.size(); i++)
        {
            prefix[i + 1] = ((long long)prefix[i] * powers[i]) % 1000000007;
        }

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            ans[i] = ((long long)prefix[queries[i][1] + 1] * inverse(prefix[queries[i][0]])) % 1000000007;
        }

        return ans;
    }
};