#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    string longestCommonPrefix(vector<string> &strs)
    {
        for(int i = 0; i < strs[0].length(); i++)
        {
            for(int j = 0; j < strs.size() - 1; j++)
            {
                if(strs[j][i] != strs[j + 1][i])
                {
                    return strs[j].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};