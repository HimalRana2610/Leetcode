#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.length() != word2.length())
        {
            return false;
        }

        int n = word1.size();
        unordered_map<char, int> freq1, freq2;

        for (int i = 0; i < n; i++)
        {
            freq1[word1[i]]++;
            freq2[word2[i]]++;
        }

        if (freq1.size() != freq2.size())
        {
            return false;
        }

        vector<int> f1, f2;
        for (auto &f : freq1)
        {
            if (freq2[f.first] == 0)
            {
                return false;
            }
            f1.push_back(f.second);
        }
        for (auto &f : freq2)
        {
            if (freq1[f.first] == 0)
            {
                return false;
            }
            f2.push_back(f.second);
        }

        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());

        for (int i = 0; i < f1.size(); i++)
        {
            if (f1[i] != f2[i])
            {
                return false;
            }
        }

        return true;
    }
};