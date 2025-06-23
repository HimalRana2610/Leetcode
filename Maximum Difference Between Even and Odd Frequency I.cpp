#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDifference(string s)
    {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
        }

        int odd = INT_MIN, even = INT_MAX;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] % 2 == 0 && freq[i] > 0)
            {
                even = min(even, freq[i]);
            }
            else
            {
                odd = max(odd, freq[i]);
            }
        }

        return odd - even;
    }
};