#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int minChanges(string s)
    {
        vector<int> c;
        int count = 1, one = 0;
        char ch = s[0];

        if(s[0] == '1')
        {
            one++;
        }
        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] == '1')
            {
                one++;
            }
            if(s[i] == ch)
            {
                count++;
            }
            else
            {
                c.push_back(count);
                ch = s[i];
                count = 1;
            }
        }
        c.push_back(count);

        int m = min(one, static_cast<int>(s.length()) - one), ans = 0;
        for(int i = 0; i < c.size() - 1; i++)
        {
            if(c[i] % 2 != 0)
            {
                ans++;
                c[i + 1]++;
            }
        }

        if(c[c.size() - 1] % 2 == 0)
        {
            return min(ans, m);
        }

        return m;
    }
};