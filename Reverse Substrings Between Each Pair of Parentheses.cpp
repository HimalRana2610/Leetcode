#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<string> st;
        string ans = "";

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push(ans);
                ans = "";
            }
            else if (s[i] == ')')
            {
                reverse(ans.begin(), ans.end());
                ans = st.top() + ans;
                st.pop();
            }
            else
            {
                ans += s[i];
            }
        }

        return ans;
    }
};