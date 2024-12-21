#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        sort(s.rbegin(), s.rend());

        string ans;
        int freq = 1, p = 0;

        for(int i = 0; i < s.length(); i++)
        {
            if(!ans.empty() && ans.back() == s[i])
            {
                if(freq < repeatLimit)
                {
                    ans += s[i];
                    freq++;
                }
                else
                {
                    p = max(p, i + 1);
                    while(p < s.length() && s[p] == s[i])
                    {
                        p++;
                    }

                    if(p < s.length())
                    {
                        ans += s[p];
                        swap(s[i], s[p]);
                        freq = 1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                ans += s[i];
                freq = 1;
            }
        }

        return ans;
    }
};