#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<int> freq(26, 0);
        for (int i = 0; i < word.length(); i++)
        {
            freq[word[i] - 'a']++;
        }

        sort(freq.rbegin(), freq.rend());

        int m = 1, ans = 0;
        for (int i = 0; i < 26 && freq[i] > 0; i++)
        {
            if (i == 8 || i == 16 || i == 24)
            {
                m++;
            }
            ans += m * freq[i];
        }

        return ans;
    }
};