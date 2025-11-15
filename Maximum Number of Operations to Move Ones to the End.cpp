#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxOperations(string s)
    {
        int ans = 0, prev = 0;
        for (int i = s.length() - 2; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                if (s[i + 1] == '0')
                {
                    ans += (++prev);
                }
                else
                {
                    ans += prev;
                }
            }
        }

        return ans;
    }
};