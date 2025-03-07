#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string reverseVowels(string s)
    {
        vector<char> vowels;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                vowels.push_back(s[i]);
            }
        }

        for(int i = s.length() - 1, j = 0; i >= 0; i--)
        {
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                s[i] = vowels[j];
                j++;
            }
        }

        return s;
    }
};