#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        int n = words.size();
        vector<string> temp = words;

        for (int i = 0; i < n; i++)
        {
            sort(temp[i].begin(), temp[i].end());
        }

        vector<string> ans = {words[0]};
        for (int i = 1; i < n; i++)
        {
            if (temp[i] != temp[i - 1])
            {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};