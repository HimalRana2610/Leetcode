#include <bits/stdc++.h>
using namespace std;

class SparseTable
{
    vector<vector<int>> mn, mx;

public:
    SparseTable(vector<int> &num)
    {
        int n = num.size();
        int w = bit_width(num.size());

        mn.resize(w, vector<int>(n));
        mx.resize(w, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            mn[0][i] = mx[0][i] = num[i];
        }

        for (int i = 1; i < w; i++)
        {
            for (int j = 0; j + (1 << i) <= n; j++)
            {
                mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
                mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int left, int right)
    {
        int k = bit_width((uint32_t)right - left) - 1;
        return max(mx[k][left], mx[k][right - (1 << k)]) - min(mn[k][left], mn[k][right - (1 << k)]);
    }
};

class Solution
{
public:
    long long maxTotalValue(vector<int> &nums, int k)
    {
        int n = nums.size();
        long long ans = 0;

        SparseTable st(nums);

        priority_queue<tuple<int, int, int>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.emplace(st.query(i, n), i, n);
        }

        while (get<0>(pq.top()) && k--)
        {
            int val = get<0>(pq.top()), l = get<1>(pq.top()), r = get<2>(pq.top());
            pq.pop();

            ans += val;
            pq.emplace(st.query(l, r - 1), l, r - 1);
        }

        return ans;
    }
};