#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDeletions(string s)
    {
        int n = s.length(), a = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'a')
            {
                a++;
            }
        }

        int b = 0, ans = n;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
            {
                a--;
            }

            ans = min(ans, a + b);
            if (s[i] == 'b')
            {
                b++;
            }
        }

        return ans;
    }
};