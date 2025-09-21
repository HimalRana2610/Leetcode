#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_vowel(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

    string sortVowels(string s)
    {
        int n = s.length();
        string vowels, ans(n, '.');

        for (int i = 0; i < n; i++)
        {
            if (is_vowel(s[i]))
            {
                vowels.push_back(s[i]);
            }
            else
            {
                ans[i] = s[i];
            }
        }

        sort(vowels.begin(), vowels.end());

        for (int i = 0, j = 0; i < n; i++)
        {
            if (ans[i] == '.')
            {
                ans[i] = vowels[j++];
            }
        }

        return ans;
    }
};