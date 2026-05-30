#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        int ans = 0;
        for (char ch = 'A'; ch <= 'Z'; ch++)
        {
            bool upper = false, lower = false;
            for (int i = 0; i < word.length(); i++)
            {
                if (word[i] == ch)
                {
                    upper = true;
                }
                if (word[i] == ch + 32)
                {
                    lower = true;
                }
                if (word[i] == ch + 32 && upper)
                {
                    lower = false;
                    break;
                }
            }

            if (upper && lower)
            {
                ans++;
            }
        }

        return ans;
    }
};