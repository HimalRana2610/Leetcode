#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int hamming_distance(string a, string b)
    {
        if(a.length() != b.length())
        {
            return -1;
        }

        int dist = 0;
        for(int i = 0; i < a.length(); i++)
        {
            if(a[i] != b[i])
            {
                dist++;
            }
        }
        return dist;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups)
    {
        int n = words.size();
        vector<int> dp(n, 1), prev(n, -1);

        int index = 0;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(groups[i] != groups[j] && hamming_distance(words[i], words[j]) == 1 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if(dp[i] > dp[index])
            {
                index = i;
            }
        }

        vector<string> ans;
        for(int i = index; i >= 0; i = prev[i])
        {
            ans.push_back(words[i]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};