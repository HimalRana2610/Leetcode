#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxActiveSectionsAfterTrade(string s)
    {
        int cnt = 1, ones = (s[0] == '1');
        vector<int> segs;

        for (int i = 1; i < s.length(); i++)
        {
            if (s[i - 1] == s[i])
            {
                cnt++;
            }
            else
            {
                segs.push_back(cnt);
                cnt = 1;
            }
            ones += (s[i] == '1');
        }
        segs.push_back(cnt);

        int ans = ones;
        bool one = (s[0] == '0');

        for (int i = 1; i < segs.size() - 1; i++, one = !one)
        {
            if (one)
            {
                ans = max(ans, ones + segs[i - 1] + segs[i + 1]);
            }
        }

        return ans;
    }
};