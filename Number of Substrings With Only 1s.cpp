#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSub(string s)
    {
        long long cnt = 0, ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
            {
                cnt++;
                ans = (ans + cnt) % 1000000007;
            }
            else
            {
                cnt = 0;
            }
        }

        return ans;
    }
};