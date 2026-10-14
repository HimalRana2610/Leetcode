#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string evaluate(string s, vector<vector<string>> &knowledge)
    {
        unordered_map<string, string> mp;
        for (int i = 0; i < knowledge.size(); i++)
        {
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        bool flag = false;
        string key, ans;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                flag = true;
                key = "";
            }
            else if (s[i] == ')')
            {
                flag = false;
                if (mp.count(key))
                {
                    ans += mp[key];
                }
                else
                {
                    ans.push_back('?');
                }
            }
            else
            {
                if (flag)
                {
                    key.push_back(s[i]);
                }
                else
                {
                    ans.push_back(s[i]);
                }
            }
        }

        return ans;
    }
};