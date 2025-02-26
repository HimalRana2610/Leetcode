#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string smallestNumber(string pattern)
    {
        int n = pattern.length(), index = 0;
        vector<int> stack(n + 1);

        string ans = "";
        for(int i = 0; i <= n; i++)
        {
            stack[index++] = i + 1;
            if(i == n || pattern[i] == 'I')
            {
                while(index > 0)
                {
                    ans += to_string(stack[--index]);
                }
            }
        }

        return ans;
    }
};