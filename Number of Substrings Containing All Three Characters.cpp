#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int numberOfSubstrings(string s)
    {
        unordered_map<char, int> freq;
        int n = s.length(), ans = 0;

        for(int i = 0, j = 0; i < n; i++)
        {
            freq[s[i]]++;
            while(freq['a'] >= 1 && freq['b'] >= 1 && freq['c'] >= 1)
            {
                ans += n - i;
                freq[s[j]]--;
                j++;
            }
        }

        return ans;
    }
};