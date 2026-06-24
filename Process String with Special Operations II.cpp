#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char processStr(string s, long long k)
    {
        int n = s.size();
        vector<long long> len(n);
        long long current = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                if (current > 0)
                {
                    current--;
                }
            }
            else if (s[i] == '#')
            {
                current = min(LLONG_MAX / 2, current) * 2;
            }
            else if (s[i] == '%')
            {
            }
            else
            {
                current++;
            }

            len[i] = current;
        }

        if (k >= current)
        {
            return '.';
        }

        for (int i = n - 1; i >= 0; i--)
        {
            long long prev = (i == 0 ? 0 : len[i - 1]);
            if (isalpha(s[i]))
            {
                if (k == prev)
                {
                    return s[i];
                }
            }
            else if (s[i] == '#')
            {
                if (prev > 0)
                {
                    k %= prev;
                }
            }
            else if (s[i] == '%')
            {
                k = prev - 1 - k;
            }
        }

        return '.';
    }
};