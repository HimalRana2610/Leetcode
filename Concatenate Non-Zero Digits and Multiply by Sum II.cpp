#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>> &queries)
    {
        int n = s.size();
        vector<int> sum(n + 1, 0), cnt(n + 1, 0);
        vector<long long> x(n + 1, 0);

        for (int i = 0; i < n; ++i)
        {
            int d = s[i] - '0';
            sum[i + 1] = sum[i] + d;
            x[i + 1] = (d > 0) ? (x[i] * 10 + d) % 1000000007 : x[i];
            cnt[i + 1] = cnt[i] + (d > 0);
        }

        vector<long long> pow10(100001);
        pow10[0] = 1;

        for (int i = 1; i <= 100000; i++)
        {
            pow10[i] = (pow10[i - 1] * 10) % 1000000007;
        }

        int m = queries.size();
        vector<int> res(m, 0);

        for (int i = 0; i < m; ++i)
        {
            int l = queries[i][0], r = queries[i][1] + 1;
            int length = cnt[r] - cnt[l];
            long long val_x = (x[r] - x[l] * pow10[length] % 1000000007 + 1000000007) % 1000000007;
            long long val_sum = sum[r] - sum[l];
            res[i] = (val_x * val_sum) % 1000000007;
        }

        return res;
    }
};