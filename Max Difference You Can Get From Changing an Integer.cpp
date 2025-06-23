#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDiff(int num)
    {
        string str = to_string(num);
        int n = str.length();
        char ch = str[0];

        for (int i = 0; i < n && ch == '9'; i++)
        {
            ch = str[i];
        }

        int ma = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == ch)
            {
                ma = ma * 10 + 9;
            }
            else
            {
                ma = ma * 10 + (str[i] - '0');
            }
        }

        ch = str[0];
        int mi = 0;

        if (ch != '1')
        {
            for (int i = 0; i < n; i++)
            {
                if (str[i] == ch)
                {
                    mi = mi * 10 + 1;
                }
                else
                {
                    mi = mi * 10 + (str[i] - '0');
                }
            }
        }
        else
        {
            for (int i = 1; i < n; i++)
            {
                if (str[i] != '0' && str[i] != '1')
                {
                    ch = str[i];
                    break;
                }
            }

            for (int i = 0; i < n; i++)
            {
                if (ch == '1')
                {
                    mi = mi * 10 + (str[i] - '0');
                }
                else
                {
                    if (str[i] == ch)
                    {
                        mi *= 10;
                    }
                    else
                    {
                        mi = mi * 10 + (str[i] - '0');
                    }
                }
            }
        }

        return ma - mi;
    }
};