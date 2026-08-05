#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumPushes(string word)
    {
        int n = word.length(), m = 1, ans = 0;
        while (n > 0)
        {
            if (n > 8)
            {
                ans += 8 * (m++);
                n -= 8;
            }
            else
            {
                ans += n * m;
                n = 0;
            }
        }

        return ans;
    }
};