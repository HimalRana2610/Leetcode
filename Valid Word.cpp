#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string word)
    {
        if (word.length() < 3)
        {
            return false;
        }

        bool vowel = false, consonant = false;
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] >= '0' && word[i] <= '9')
            {
                continue;
            }
            else if ((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z'))
            {
                if (word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U' || word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
                {
                    vowel = true;
                }
                else
                {
                    consonant = true;
                }
            }
            else
            {
                return false;
            }
        }

        return vowel && consonant;
    }
};