#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        static const long long MOD = 1000000007LL;
        int n = (int)nums.size();
        int q = (int)queries.size();
        int block = max(1, (int)sqrt((double)q));
        block = min(block, n);

        vector<long long> inv(100001, 1);
        for (int i = 2; i <= 100000; ++i)
        {
            inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
        }

        vector<vector<array<int, 3>>> small(block + 1);

        for (const auto &query : queries)
        {
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];

            if (k > block)
            {
                for (int index = l; index <= r; index += k)
                {
                    nums[index] = (long long)nums[index] * v % MOD;
                }
            }
            else
            {
                small[k].push_back({l, r, v});
            }
        }

        for (int k = 1; k <= block; ++k)
        {
            if (small[k].empty())
            {
                continue;
            }

            vector<int> len(k);
            for (int residue = 0; residue < k; ++residue)
            {
                len[residue] = (n - 1 - residue) / k + 1;
            }

            vector<vector<long long>> diff(k);
            for (int residue = 0; residue < k; ++residue)
            {
                diff[residue].assign(len[residue] + 1, 1);
            }

            for (const auto &query : small[k])
            {
                int l = query[0];
                int r = query[1];
                int v = query[2];
                int residue = l % k;
                int start = l / k;
                int end = (r - residue) / k;

                diff[residue][start] = diff[residue][start] * v % MOD;
                diff[residue][end + 1] = diff[residue][end + 1] * inv[v] % MOD;
            }

            for (int residue = 0; residue < k; ++residue)
            {
                long long current = 1;
                for (int pos = 0; pos < len[residue]; ++pos)
                {
                    current = current * diff[residue][pos] % MOD;
                    int index = residue + pos * k;
                    nums[index] = (long long)nums[index] * current % MOD;
                }
            }
        }

        int answer = 0;
        for (int value : nums)
        {
            answer ^= value;
        }

        return answer;
    }
};