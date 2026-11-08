#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_sorted(string &s)
    {
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] < s[i - 1])
            {
                return false;
            }
        }
        return true;
    }

    int minOperations(string s)
    {
        int n = s.length();
        char mx = 'a', mn = 'z';

        for (int i = 0; i < n; i++)
        {
            mx = max(mx, s[i]);
            mn = min(mn, s[i]);
        }

        if (is_sorted(s))
        {
            return 0;
        }
        if (n == 2)
        {
            return -1;
        }
        if (s[0] == mn || s[n - 1] == mx)
        {
            return 1;
        }

        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] == mn || s[i] == mx)
            {
                return 2;
            }
        }

        return 3;
    }
};