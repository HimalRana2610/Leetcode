#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string makeFancyString(string s)
    {
        string ans = "";
        char ch = s[0];
        int count = 1;

        ans.push_back(ch);
        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] == ch)
            {
                count++;
            }
            else
            {
                ch = s[i];
                count = 1;
            }

            if(count < 3)
            {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};