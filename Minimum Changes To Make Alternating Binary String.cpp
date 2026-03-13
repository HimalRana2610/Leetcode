#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(string s)
    {
        bool zero = true;
        int n = s.length(), ans1 = 0;

        for (int i = 0; i < n; i++, zero = !zero)
        {
            if ((zero && s[i] == '1') || (!zero && s[i] == '0'))
            {
                ans1++;
            }
        }

        zero = false;
        int ans2 = 0;

        for (int i = 0; i < n; i++, zero = !zero)
        {
            if ((zero && s[i] == '1') || (!zero && s[i] == '0'))
            {
                ans2++;
            }
        }

        return min(ans1, ans2);
    }
};