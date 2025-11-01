#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasSameDigits(string s)
    {
        while (s.length() != 2)
        {
            string next;
            for (int i = 1; i < s.length(); i++)
            {
                next.push_back(((s[i] - '0') + (s[i - 1] - '0')) % 10 + '0');
            }
            s = next;
        }

        return s[0] == s[1];
    }
};