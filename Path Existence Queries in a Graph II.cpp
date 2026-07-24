#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
    {
        vector<int> idx(n), pos(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b)
             { return nums[a] < nums[b]; });

        for (int i = 0; i < n; i++)
        {
            pos[idx[i]] = i;
        }

        int m = 32 - __builtin_clz(n);
        vector<vector<int>> f(n, vector<int>(m));

        for (int i = 0, j = 0; i < n; i++)
        {
            while (nums[idx[i]] - nums[idx[j]] > maxDiff)
            {
                j++;
            }
            f[i][0] = j;
        }

        for (int j = 1; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                f[i][j] = f[f[i][j - 1]][j - 1];
            }
        }

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            int x = pos[queries[i][0]], y = pos[queries[i][1]];
            if (x > y)
            {
                swap(x, y);
            }
            if (x == y)
            {
                ans.push_back(0);
                continue;
            }

            int step = 0;
            for (int j = m - 1; j >= 0; j--)
            {
                if (f[y][j] > x)
                {
                    y = f[y][j];
                    step += 1 << j;
                }
            }

            ans.push_back(f[y][0] <= x ? step + 1 : -1);
        }

        return ans;
    }
};