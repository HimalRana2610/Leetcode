#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        int ans = 0;
        vector<char> st, temp;

        if (x >= y)
        {
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == 'b' && !st.empty() && st.back() == 'a')
                {
                    ans += x;
                    st.pop_back();
                }
                else
                {
                    st.push_back(s[i]);
                }
            }

            for (int i = 0; i < st.size(); i++)
            {
                if (st[i] == 'a' && !temp.empty() && temp.back() == 'b')
                {
                    ans += y;
                    temp.pop_back();
                }
                else
                {
                    temp.push_back(st[i]);
                }
            }
        }
        else
        {
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == 'a' && !st.empty() && st.back() == 'b')
                {
                    ans += y;
                    st.pop_back();
                }
                else
                {
                    st.push_back(s[i]);
                }
            }

            for (int i = 0; i < st.size(); i++)
            {
                if (st[i] == 'b' && !temp.empty() && temp.back() == 'a')
                {
                    ans += x;
                    temp.pop_back();
                }
                else
                {
                    temp.push_back(st[i]);
                }
            }
        }

        return ans;
    }
};