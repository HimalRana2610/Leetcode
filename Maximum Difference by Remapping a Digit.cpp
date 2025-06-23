#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMaxDifference(int num)
    {
        string str = to_string(num);
        char ch = str[0];

        int n = str.length(), mi = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == ch)
            {
                mi = (mi * 10);
            }
            else
            {
                mi = (mi * 10) + (str[i] - '0');
            }
        }

        for (int i = 1; i < n && ch == '9'; i++)
        {
            ch = str[i];
        }

        int ma = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == ch)
            {
                ma = (ma * 10) + 9;
            }
            else
            {
                ma = (ma * 10) + (str[i] - '0');
            }
        }

        return ma - mi;
    }
};