#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool is_vowel(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries)
    {
        int n = words.size(), m = queries.size();
        vector<int> prefix(n + 1, 0);

        for(int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i];
            if(is_vowel(words[i][0]) && is_vowel(words[i][words[i].length() - 1]))
            {
                prefix[i + 1]++;
            }
        }

        vector<int> ans(m);
        for(int i = 0; i < m; i++)
        {
            ans[i] = prefix[queries[i][1] + 1] - prefix[queries[i][0]];
        }

        return ans;
    }
};