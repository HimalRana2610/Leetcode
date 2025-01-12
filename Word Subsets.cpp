#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2)
    {
        unordered_map<char, int> freq;
        for(int i = 0; i < words2.size(); i++)
        {
            unordered_map<char, int> word_freq;
            for(int j = 0; j < words2[i].length(); j++)
            {
                word_freq[words2[i][j]]++;
            }
            for(const auto &f : word_freq)
            {
                freq[f.first] = max(freq[f.first], f.second);
            }
        }

        vector<string> ans;
        for(int i = 0; i < words1.size(); i++)
        {
            unordered_map<char, int> word_freq;
            for(int j = 0; j < words1[i].length(); j++)
            {
                word_freq[words1[i][j]]++;
            }

            bool flag = true;
            for(const auto &f : freq)
            {
                if(word_freq[f.first] < f.second)
                {
                    flag = false;
                    break;
                }
            }

            if(flag)
            {
                ans.push_back(words1[i]);
            }
        }

        return ans;
    }
};