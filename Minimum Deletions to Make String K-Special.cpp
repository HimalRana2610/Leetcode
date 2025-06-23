#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDeletions(string word, int k)
    {
        vector<int> freq(26, 0);
        for (int i = 0; i < word.length(); i++)
        {
            freq[word[i] - 'a']++;
        }

        int ans = INT_MAX;
        for (int i = 0; i < 26; i++)
        {
            int current = 0;
            for (int j = 0; j < 26; j++)
            {
                if (freq[i] > freq[j])
                {
                    current += freq[j];
                }
                else if (freq[i] + k < freq[j])
                {
                    current += freq[j] - (freq[i] + k);
                }
            }
            ans = min(ans, current);
        }

        return ans;
    }
};