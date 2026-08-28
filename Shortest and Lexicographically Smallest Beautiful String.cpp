#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(string &s, int len, int k, bool &found, string &ans)
    {
        int one = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '1')
            {
                one++;
            }
        }

        if (one == k)
        {
            found = true;
            ans = min(ans, s.substr(0, len));
        }

        for (int i = len; i < s.length(); i++)
        {
            if (s[i] == '1')
            {
                one++;
            }

            if (s[i - len] == '1')
            {
                one--;
            }

            if (one == k)
            {
                found = true;
                ans = min(ans, s.substr(i - len + 1, len));
            }
        }
    }

    string shortestBeautifulSubstring(string s, int k)
    {
        bool found = false;
        string ans(s.length() + 1, '1');

        for (int i = k; i <= s.length() && !found; i++)
        {
            solve(s, i, k, found, ans);
        }

        if (!found)
        {
            return "";
        }

        return ans;
    }
};