#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool isPrefixAndSuffix(string a, string b)
    {
        if(a.length() > b.length())
        {
            return false;
        }

        for(int i = 0, j = 0; i < a.length(); i++, j++)
        {
            if(a[i] != b[j])
            {
                return false;
            }
        }
        for(int i = a.length() - 1, j = b.length() - 1; i >= 0; i--, j--)
        {
            if(a[i] != b[j])
            {
                return false;
            }
        }

        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words)
    {
        int ans = 0;
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = i + 1; j < words.size(); j++)
            {
                if(isPrefixAndSuffix(words[i], words[j]))
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};