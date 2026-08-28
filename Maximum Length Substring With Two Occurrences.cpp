#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int i = 0, ans = 0;
        vector<int> freq(26, 0);

        for (int j = 0; j < s.length(); j++)
        {
            freq[s[j] - 'a']++;
            while (freq[s[j] - 'a'] > 2)
            {
                freq[s[i++] - 'a']--;
            }
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};