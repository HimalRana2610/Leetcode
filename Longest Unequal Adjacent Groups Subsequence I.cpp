#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups)
    {
        vector<string> ans;
        ans.push_back(words[0]);

        int prev = groups[0];
        for(int i = 1; i < words.size(); i++)
        {
            if(groups[i] != prev)
            {
                ans.push_back(words[i]);
                prev = groups[i];
            }
        }

        return ans;
    }
};