#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int ans = 0, cnt = 1, prev = 0;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i - 1] != s[i])
            {
                ans += min(prev, cnt);
                prev = cnt;
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }

        ans += min(prev, cnt);
        return ans;
    }
};