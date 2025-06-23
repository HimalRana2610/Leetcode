#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string robotWithString(string s)
    {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
        }

        stack<char> st;
        char m = 'a';

        string ans;
        for (int i = 0; i < s.length(); i++)
        {
            st.push(s[i]);
            freq[s[i] - 'a']--;

            while (m != 'z' && freq[m - 'a'] == 0)
            {
                m++;
            }
            while (!st.empty() && st.top() <= m)
            {
                ans.push_back(st.top());
                st.pop();
            }
        }

        return ans;
    }
};