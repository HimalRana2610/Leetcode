#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        vector<int> freq(26, 0);
        for (int i = 0; i < text.length(); i++)
        {
            freq[text[i] - 'a']++;
        }

        unordered_map<char, int> balloon = {{'a', 1}, {'b', 1}, {'l', 2}, {'n', 1}, {'o', 2}};
        int ans = INT_MAX;

        for (auto &f : balloon)
        {

            ans = min(ans, freq[f.first - 'a'] / f.second);
        }

        return ans;
    }
};