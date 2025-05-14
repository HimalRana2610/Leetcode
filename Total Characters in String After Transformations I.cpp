#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int lengthAfterTransformations(string s, int t)
    {
        vector<int> freq(26, 0);
        for(int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
        }

        for(int i = 0; i < t; i++)
        {
            vector<int> new_freq(26, 0);
            new_freq[0] = freq[25];
            new_freq[1] = (freq[0] + freq[25]) % 1000000007;

            for(int j = 2; j < 26; j++)
            {
                new_freq[j] = freq[j - 1];
            }

            freq = move(new_freq);
        }

        int ans = 0;
        for(int i = 0; i < 26; i++)
        {
            ans = (ans + freq[i]) % 1000000007;
        }

        return ans;
    }
};