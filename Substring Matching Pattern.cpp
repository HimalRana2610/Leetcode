#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool hasMatch(string s, string p)
    {
        int pos = p.find('*');
        string prefix = p.substr(0, pos), suffix = p.substr(pos + 1);

        if(s.find(prefix) == string::npos || s.find(suffix) == string::npos)
        {
            return false;
        }

        int i = s.find(prefix), j = s.rfind(suffix);
        if(j < i + prefix.length())
        {
            return false;
        }

        return true;
    }
};