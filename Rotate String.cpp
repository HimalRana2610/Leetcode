#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void rotate(string &str)
    {
        char ch = str[0];
        for(int i = 0; i < str.length() - 1; i++)
        {
            str[i] = str[i + 1];
        }
        str[str.length() - 1] = ch;
    }
    bool rotateString(string s, string goal)
    {
        for(int i = 0; i < s.length(); i++)
        {
            if(s == goal)
            {
                return true;
            }
            rotate(s);
        }
        return false;
    }
};