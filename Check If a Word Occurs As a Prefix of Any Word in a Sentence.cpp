#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool is_prefix(string word, string prefix)
    {
        for(int i = 0; i < prefix.length(); i++)
        {
            if(word[i]!= prefix[i])
            {
                return false;
            }
        }
        return true;
    }

    int isPrefixOfWord(string sentence, string searchWord)
    {
        vector<string> words;
        int p = 0;

        for(int i = 0; i < sentence.length(); i++)
        {
            if(sentence[i] == ' ')
            {
                words.push_back(sentence.substr(p, i - p));
                p = i + 1;
            }
        }
        words.push_back(sentence.substr(p));

        for(int i = 0; i < words.size(); i++)
        {
            if(is_prefix(words[i], searchWord))
            {
                return i + 1;
            }
        }
        return -1;
    }
};