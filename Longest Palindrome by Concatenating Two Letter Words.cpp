#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> freq;
        int ans = 0;

        for (int i = 0; i < words.size(); i++)
        {
            freq[words[i]]++;
        }

        int cnt = 0, taken = 0;
        for (auto &f : freq)
        {
            string str = f.first;
            string rev = str;
            reverse(rev.begin(), rev.end());

            if (str == rev)
            {
                cnt += (freq[str] / 2) * 4;
                if (freq[str] % 2 != 0)
                {
                    taken = 1;
                }
            }
            else if (str < rev && freq.count(rev))
            {
                cnt += min(freq[str], freq[rev]) * 4;
            }
        }

        return cnt + taken * 2;
    }
};