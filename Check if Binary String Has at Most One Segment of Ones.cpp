#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        int one = 0;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i - 1] == '1' && s[i] == '0')
            {
                one++;
            }
        }

        if (s.back() == '1')
        {
            one++;
        }

        return one <= 1;
    }
};