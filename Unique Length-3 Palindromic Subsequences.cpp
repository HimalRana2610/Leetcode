#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int countPalindromicSubsequence(string s)
    {
        int n = s.length(), ans = 0;
        unordered_set<char> chars(s.begin(), s.end());
        for(char ch : chars)
        {
            int left = 0, right = 0;
            for(int i = 0; i < n; i++)
            {
                if(s[i] == ch)
                {
                    left = i;
                    break;
                }
            }

            for(int i = n - 1; i >= 0; i--)
            {
                if(s[i] == ch)
                {
                    right = i;
                    break;
                }
            }

            if(left == right || left == right - 1)
            {
                continue;
            }

            unordered_set<char> temp(s.begin() + left + 1, s.begin() + right);
            ans += temp.size();
        }

        return ans;
    }
};