#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int possibleStringCount(string word)
    {
        vector<int> freq(26, 0);
        for (int i = 1; i < word.size(); i++)
        {
            if (word[i] == word[i - 1])
            {
                freq[word[i] - 'a']++;
            }
        }

        int ans = 1;
        for (int i = 0; i < 26; i++)
        {
            ans += freq[i];
        }

        return ans;
    }
};