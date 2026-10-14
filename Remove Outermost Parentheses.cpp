#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int cnt = 0;
        string ans;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                if (cnt > 0)
                {
                    ans.push_back('(');
                }
                cnt++;
            }
            else
            {
                if (cnt > 1)
                {
                    ans.push_back(')');
                }
                cnt--;
            }
        }

        return ans;
    }
};