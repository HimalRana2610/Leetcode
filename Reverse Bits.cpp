#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverseBits(int n)
    {
        string str;
        while (n > 0)
        {
            if (n % 2 == 0)
            {
                str.push_back('0');
            }
            else
            {
                str.push_back('1');
            }
            n >>= 1;
        }

        while (str.length() != 32)
        {
            str.push_back('0');
        }

        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            if (str[i] == '1')
            {
                ans += (1 << (31 - i));
            }
        }

        return ans;
    }
};