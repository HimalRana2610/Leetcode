#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDistance(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
        for (auto &it : mp)
        {
            if (it.second.size() >= 3)
            {
                vector<int> &v = it.second;
                int m = v.size();

                for (int i = 0; i < m - 2; i++)
                {
                    ans = min(ans, abs(v[i] - v[i + 1]) + abs(v[i + 1] - v[i + 2]) + abs(v[i + 2] - v[i]));
                }
            }
        }

        if (ans == INT_MAX)
        {
            return -1;
        }

        return ans;
    }
};