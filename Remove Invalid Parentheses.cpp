#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backtrack(string s, vector<string> &ans, int x, int y)
    {
        int balance = 0;
        for (int i = x; i >= 0; i--)
        {
            balance += (s[i] == ')') - (s[i] == '(');
            if (balance >= 0)
            {
                continue;
            }

            for (int j = y; j >= i; j--)
            {
                if (s[j] == '(' && (j == y || s[j + 1] != '('))
                {
                    backtrack(s.substr(0, j) + s.substr(j + 1), ans, i - 1, j - 1);
                }
            }

            return;
        }

        ans.push_back(s);
    }

    void solve(string s, vector<string> &ans, int x, int y)
    {
        int balance = 0;
        for (int i = x; i < s.length(); i++)
        {
            balance += (s[i] == '(') - (s[i] == ')');
            if (balance >= 0)
            {
                continue;
            }

            for (int j = y; j <= i; j++)
            {
                if (s[j] == ')' && (j == y || s[j - 1] != ')'))
                {
                    solve(s.substr(0, j) + s.substr(j + 1), ans, i, j);
                }
            }

            return;
        }

        backtrack(s, ans, s.length() - 1, s.length() - 1);
    }

    vector<string> removeInvalidParentheses(string s)
    {
        vector<string> ans;
        solve(s, ans, 0, 0);

        return ans;
    }
};