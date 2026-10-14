#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        stack<int> st;
        st.push(0);

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push(0);
            }
            else
            {
                int current = st.top();
                st.pop();

                int next = st.top() + max(2 * current, 1);
                st.pop();
                st.push(next);
            }
        }

        return st.top();
    }
};