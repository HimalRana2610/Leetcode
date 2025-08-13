#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minCost(vector<int> &basket1, vector<int> &basket2)
    {
        unordered_map<int, int> freq;
        int n = basket1.size(), m = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            freq[basket1[i]]++;
            m = min(m, basket1[i]);
        }
        for (int i = 0; i < n; i++)
        {
            freq[basket2[i]]--;
            m = min(m, basket2[i]);
        }

        vector<int> total;
        for (auto &f : freq)
        {
            if (f.second % 2 != 0)
            {
                return -1;
            }

            for (int i = 0; i < abs(f.second) / 2; i++)
            {
                total.push_back(f.first);
            }
        }

        int l = total.size();
        nth_element(total.begin(), total.begin() + l / 2, total.end());

        return accumulate(total.begin(), total.begin() + l / 2, 0LL, [&](long long ans, int x)
                          { return ans + min(2 * m, x); });
    }
};