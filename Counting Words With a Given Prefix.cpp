#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool is_prefix(string str, string pref)
    {
        if(str.length() < pref.length())
        {
            return false;
        }

        for(int i = 0; i < pref.length(); i++)
        {
            if(str[i] != pref[i])
            {
                return false;
            }
        }

        return true;
    }

    int prefixCount(vector<string>& words, string pref)
    {
        int ans = 0;
        for(int i = 0; i < words.size(); i++)
        {
            if(is_prefix(words[i], pref))
            {
                ans++;
            }
        }

        return ans;
    }
};