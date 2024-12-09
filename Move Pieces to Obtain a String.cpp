#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool canChange(string start, string target)
    {
        string str = start, tar = target;
        str.erase(remove(str.begin(), str.end(), '_'), str.end());
        tar.erase(remove(tar.begin(), tar.end(), '_'), tar.end());

        if(str != tar)
        {
            return false;
        }

        int n = start.length();
        for(int i = 0, j = 0; i < n && j < n; i++, j++)
        {
            while(i < n && start[i] == '_')
            {
                i++;
            }
            while(j < n && target[j] == '_')
            {
                j++;
            }
            if(start[i] !=  target[j])
            {
                return false;
            }
            if(start[i] == 'L' && i < j)
            {
                return false;
            }
            if(start[i] == 'R' && i > j)
            {
                return false;
            }
        }
        return true;
    }
};