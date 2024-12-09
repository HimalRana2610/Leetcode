#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool canMakeSubsequence(string str1, string str2)
    {
        int j = 0;
        for(int i = 0; i < str1.length() && j < str2.length(); i++)
        {
            if(str2[j] - str1[i] == 0 || str2[j] - str1[i] == 1 || (str2[j] == 'a' && str1[i] == 'z'))
            {
                j++;
            }
        }
        return j == str2.length();
    }
};