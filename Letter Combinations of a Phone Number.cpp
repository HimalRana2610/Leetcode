#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int index, string &digits, vector<string> &keypad, string current, vector<string> &ans)
    {
        if (index == digits.length())
        {
            ans.push_back(current);
            return;
        }

        int n = digits[index] - '0';
        for (int i = 0; i < keypad[n].length(); i++)
        {
            current.push_back(keypad[n][i]);
            dfs(index + 1, digits, keypad, current, ans);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> ans, keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (digits.empty())
        {
            return ans;
        }

        dfs(0, digits, keypad, "", ans);
        return ans;
    }
};