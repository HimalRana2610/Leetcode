#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string findValidPair(string s)
    {
        unordered_map<char, int> freq;
        for(int i = 0; i < s.length(); i++)
        {
            freq[s[i]]++;
        }

        string ans;
        for(int i = 1; i < s.length(); i++)
        {
            if(s[i - 1] != s[i] && freq[s[i - 1]] == s[i - 1] - '0' && freq[s[i]] == s[i] - '0')
            {
                ans.push_back(s[i - 1]);
                ans.push_back(s[i]);
                break;
            }
        }

        return ans;
    }
};