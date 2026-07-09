#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numOfStrings(vector<string> &patterns, string word)
    {
        int n = word.length();
        unordered_set<string> s;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                s.insert(word.substr(i, j - i + 1));
            }
        }

        int ans = 0;
        for (int i = 0; i < patterns.size(); i++)
        {
            if (s.find(patterns[i]) != s.end())
            {
                ans++;
            }
        }

        return ans;
    }
};