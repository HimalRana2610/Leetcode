#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeStars(string s)
    {
        string ans;
        int stars = 0;

        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '*')
            {
                stars++;
            }
            else
            {
                if (stars == 0)
                {
                    ans.push_back(s[i]);
                }
                else
                {
                    stars--;
                }
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};