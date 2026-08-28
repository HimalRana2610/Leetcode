#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int pos, string &ans, string &target, vector<int> &freq, bool greater)
    {
        if (pos == target.size())
        {
            return greater;
        }

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] == 0)
            {
                continue;
            }

            char ch = 'a' + i;
            if (!greater && ch < target[pos])
            {
                continue;
            }

            freq[i]--;
            ans.push_back(ch);

            if (dfs(pos + 1, ans, target, freq, greater || ch > target[pos]))
            {
                return true;
            }

            ans.pop_back();
            freq[i]++;
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target)
    {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
        }

        string ans;
        if (dfs(0, ans, target, freq, false))
        {
            return ans;
        }

        return "";
    }
};