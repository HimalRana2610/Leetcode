#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            if (word.find('A' + i) != string::npos && word.find('a' + i) != string::npos)
            {
                ans++;
            }
        }

        return ans;
    }
};