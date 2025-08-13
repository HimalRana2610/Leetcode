#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_palindrome(const string &s, int start, int end)
    {
        while (start < end)
        {
            if (s[start++] != s[end--])
            {
                return false;
            }
        }

        return true;
    }

    void solve(string &s, int index, vector<string> &current, vector<vector<string>> &ans)
    {
        if (index == s.length())
        {
            ans.push_back(current);
            return;
        }

        for (int i = index; i < s.length(); i++)
        {
            if (is_palindrome(s, index, i))
            {
                current.push_back(s.substr(index, i - index + 1));
                solve(s, i + 1, current, ans);
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> current;

        solve(s, 0, current, ans);
        return ans;
    }
};