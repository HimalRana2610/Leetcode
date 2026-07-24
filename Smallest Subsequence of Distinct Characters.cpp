#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestSubsequence(string s)
    {
        vector<int> index(26, -1);
        for (int i = 0; i < s.length(); i++)
        {
            index[s[i] - 'a'] = i;
        }

        vector<bool> visited(26, false);
        string ans = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (visited[s[i] - 'a'])
            {
                continue;
            }

            while (!ans.empty() && ans.back() > s[i] && index[ans.back() - 'a'] > i)
            {
                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(s[i]);
            visited[s[i] - 'a'] = true;
        }

        return ans;
    }
};