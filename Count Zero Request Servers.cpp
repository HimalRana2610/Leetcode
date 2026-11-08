#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countServers(int n, vector<vector<int>> &logs, int x, vector<int> &queries)
    {
        sort(logs.begin(), logs.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });

        int left = 0, right = 0, active = 0;
        vector<int> ids(queries.size()), ans(queries.size()), cnt(n + 1);
        iota(ids.begin(), ids.end(), 0);

        sort(ids.begin(), ids.end(), [&](int i, int j)
             { return queries[i] < queries[j]; });

        for (int i : ids)
        {
            int q = queries[i];
            while (right < logs.size() && logs[right][1] <= q)
            {
                int id = logs[right++][0];
                if (cnt[id]++ == 0)
                {
                    active++;
                }
            }
            while (left < right && logs[left][1] < q - x)
            {
                int id = logs[left++][0];
                if (--cnt[id] == 0)
                {
                    active--;
                }
            }
            ans[i] = n - active;
        }

        return ans;
    }
};