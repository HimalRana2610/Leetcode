#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int depth = 0, ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                ans = max(ans, ++depth);
            }
            else if (s[i] == ')')
            {
                depth--;
            }
        }

        return ans;
    }
};