#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool isCircularSentence(string sentence)
    {
        vector<string> words;
        
        int p = 0;
        for(int i = 2; i < sentence.length() - 1; i++)
        {
            if(sentence[i] == ' ')
            {
                words.push_back(sentence.substr(p, i - p));
                p = i + 1;
            }
        }
        words.push_back(sentence.substr(p, sentence.length() - p));

        bool ans = true;
        if(words[0][0] != words[words.size() - 1][words[words.size() - 1].length() - 1])
        {   
            return false;
        }
        
        for(int i = 1; i < words.size() - 1; i++)
        {
            if(words[i][0] != words[i - 1][words[i - 1].length() - 1])
            {
                return false;
            }
        }
        
        return ans;
    }
};