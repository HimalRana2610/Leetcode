#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool canConstruct(string s, int k)
    {
        if(k > s.length())
        {
            return false;
        }

        unordered_map<char, int> freq;
        for(int i = 0; i < s.length(); i++)
        {
            freq[s[i]]++;
        }

        int odd = 0;
        for(const auto &f : freq)
        {
            if(f.second % 2 != 0)
            {
                odd++;
            }
        }

        return odd <= k;
    }
};