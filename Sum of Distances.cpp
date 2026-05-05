#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> distance(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, vector<long long>> mp;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n);
        for (auto &p : mp)
        {
            int m = p.second.size();
            long long total = accumulate(p.second.begin(), p.second.end(), 0LL), prefix = 0;

            for (int i = 0; i < m; i++)
            {
                ans[p.second[i]] = total - 2 * prefix + (2 * i - m) * p.second[i];
                prefix += p.second[i];
            }
        }

        return ans;
    }
};