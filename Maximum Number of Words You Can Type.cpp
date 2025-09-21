#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        stringstream ss(text);
        string word;
        vector<string> words;

        while (getline(ss, word, ' '))
        {
            words.push_back(word);
        }

        int ans = words.size();
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < brokenLetters.size(); j++)
            {
                if (words[i].find(brokenLetters[j]) != string::npos)
                {
                    ans--;
                    break;
                }
            }
        }

        return ans;
    }
};