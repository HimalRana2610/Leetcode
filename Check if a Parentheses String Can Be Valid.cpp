#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool canBeValid(string s, string locked)
    {
        int n = s.length(), open = 0, flexible = 0;
        if(n % 2 != 0)
        {
            return false;
        }

        for(int i = 0; i < n; i++)
        {
            if(locked[i] == '0')
            {
                flexible++;
            }
            else if(s[i] == '(')
            {
                open++;
            }
            else
            {
                if(open > 0)
                {
                    open--;
                }
                else if(flexible > 0)
                {
                    flexible--;
                }
                else
                {
                    return false;
                }
            }
        }

        int close = 0;
        flexible = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            if(locked[i] == '0')
            {
                flexible++;
            }
            else if(s[i] == ')')
            {
                close++;
            }
            else
            {
                if(close > 0)
                {
                    close--;
                }
                else if(flexible > 0)
                {
                    flexible--;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};