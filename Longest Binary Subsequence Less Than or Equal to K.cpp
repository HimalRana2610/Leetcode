#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubsequence(string s, int k)
    {
        int n = s.length(), num = 0, bits = 32 - __builtin_clz(k), ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[n - i - 1] == '1')
            {
                if (i < bits && num + (1 << i) <= k)
                {
                    num += (1 << i);
                    ans++;
                }
            }
            else
            {
                ans++;
            }
        }

        return ans;
    }
};