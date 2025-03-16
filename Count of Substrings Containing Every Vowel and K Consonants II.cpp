#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool is_vowel(char ch)
    {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    long long countOfSubstrings(string word, int k)
    {
        int n = word.length();
        unordered_map<char, int> vowels;
        
        vector<int> next_consonant(n);
        int last = n;
        
        for(int i = n - 1; i >= 0; i--)
        {
            next_consonant[i] = last;
            if(!is_vowel(word[i]))
            {
                last = i;
            }
        }

        int consonants = 0, left = 0, right = 0;
        long long ans = 0;

        while(right < n)
        {
            if(is_vowel(word[right]))
            {
                vowels[word[right]]++;
            }
            else
            {
                consonants++;
            }

            while(left <= right && consonants > k)
            {
                if(is_vowel(word[left]))
                {
                    if(--vowels[word[left]] == 0)
                    {
                        vowels.erase(word[left]);
                    }
                }
                else
                {
                    consonants--;
                }

                left++;
            }

            while(left < right && vowels.size() == 5 && consonants == k)
            {
                ans += (next_consonant[right] - right);
                if (is_vowel(word[left]))
                {
                    if (--vowels[word[left]] == 0)
                    {
                        vowels.erase(word[left]);
                    }
                }
                else
                {
                    consonants--;
                }

                left++;
            }

            right++;
        }

        return ans;
    }
};