#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> solveQueries(vector<int> &nums, vector<int> &queries)
    {
        int n = nums.size(), m = queries.size();
        vector<int> ans(m, -1);
        unordered_map<int, vector<int>> pos;

        for (int i = 0; i < n; i++)
        {
            pos[nums[i]].push_back(i);
        }

        auto circularDist = [&](int a, int b) -> int
        {
            int d = abs(a - b);
            return min(d, n - d);
        };

        for (int qi = 0; qi < m; qi++)
        {
            int idx = queries[qi];
            vector<int> &v = pos[nums[idx]];

            if (v.size() <= 1)
            {
                ans[qi] = -1;
                continue;
            }

            int at = lower_bound(v.begin(), v.end(), idx) - v.begin();

            int prevPos = (at == 0 ? v.back() : v[at - 1]);
            int nextPos = (at + 1 == (int)v.size() ? v.front() : v[at + 1]);

            ans[qi] = min(circularDist(idx, prevPos), circularDist(idx, nextPos));
        }

        return ans;
    }
};