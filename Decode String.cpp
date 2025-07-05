#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        stack<string> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ']')
            {
                string str;
                while (st.top() != "[")
                {
                    reverse(st.top().begin(), st.top().end());
                    str += st.top();
                    st.pop();
                }
                st.pop();

                reverse(str.begin(), str.end());

                string num;
                while (!st.empty() && st.top() >= "0" && st.top() <= "9")
                {
                    num += st.top();
                    st.pop();
                }

                reverse(num.begin(), num.end());

                string actual;
                for (int i = 0; i < stoi(num); i++)
                {
                    actual += str;
                }

                st.push(actual);
            }
            else
            {
                st.push(string(1, s[i]));
            }
        }

        string ans;
        while (!st.empty())
        {
            reverse(st.top().begin(), st.top().end());
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};