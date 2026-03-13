#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int binaryGap(int n)
    {
        string str;
        while (n > 0)
        {
            if (n % 2 == 0)
            {
                str = '0' + str;
            }
            else
            {
                str = '1' + str;
            }
            n >>= 1;
        }

        int cnt = 0, ans = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '1')
            {
                ans = max(ans, cnt);
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }

        return ans;
    }
};