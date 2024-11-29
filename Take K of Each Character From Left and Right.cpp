#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int takeCharacters(string s, int k)
    {
        int n = s.length();
        map<char, int> freq;

        for(int i = 0; i < n; i++)
        {
            freq[s[i]]++;
        }

        if(freq['a'] < k || freq['b'] < k || freq['c'] < k)
        {
            return -1;
        }

        int j = 0, ans = n, w = 0;
        for(int i = 0; i < n; i++)
        {
            freq[s[i]]--;
            w++;

            while(freq[s[i]] < k)
            {
                freq[s[j++]]++;
                w--;
            }

            ans = min(ans, n - w);
        }
        return ans;
    }
};