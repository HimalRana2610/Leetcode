#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasAlternatingBits(int n)
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

        for (int i = 1; i < str.length(); i++)
        {
            if (str[i - 1] == str[i])
            {
                return false;
            }
        }

        return true;
    }
};