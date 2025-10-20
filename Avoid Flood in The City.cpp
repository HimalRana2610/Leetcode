#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        int n = rains.size();
        vector<int> ans(n, 1);
        set<int> s;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            if (rains[i] == 0)
            {
                s.insert(i);
            }
            else
            {
                ans[i] = -1;
                if (mp.count(rains[i]))
                {
                    auto it = s.lower_bound(mp[rains[i]]);
                    if (it == s.end())
                    {
                        return {};
                    }

                    ans[*it] = rains[i];
                    s.erase(it);
                }
                mp[rains[i]] = i;
            }
        }

        return ans;
    }
};