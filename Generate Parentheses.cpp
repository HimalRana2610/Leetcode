#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(string current, int open, int close, vector<string> &ans)
    {
        if (open == 0 && close == 0)
        {
            ans.push_back(current);
            return;
        }

        if (open == close)
        {
            solve(current + "(", open - 1, close, ans);
        }
        else if (open == 0)
        {
            solve(current + ")", open, close - 1, ans);
        }
        else if (close == 0)
        {
            solve(current + "(", open - 1, close, ans);
        }
        else
        {
            solve(current + "(", open - 1, close, ans);
            solve(current + ")", open, close - 1, ans);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        solve("", n, n, ans);

        return ans;
    }
};