#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_vowel(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxFreqSum(string s)
    {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
        }

        int vowel = 0, consonent = 0;
        for (int i = 0; i < 26; i++)
        {
            if (is_vowel('a' + i))
            {
                vowel = max(vowel, freq[i]);
            }
            else
            {
                consonent = max(consonent, freq[i]);
            }
        }

        return vowel + consonent;
    }
};