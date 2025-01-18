#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int minimumLength(string s)
    {
        unordered_map<char, int> freq;
        for(int i = 0; i < s.length(); i++)
        {
            freq[s[i]]++;
        }

        int ans = 0;
        for(const auto &f : freq)
        {
            if(f.second >= 3)
            {
                if(f.second % 2 == 0)
                {
                    ans += 2;
                }
                else
                {
                    ans++;
                }
            }
            else
            {
                ans += f.second;
            }
        }

        return ans;
    }
};