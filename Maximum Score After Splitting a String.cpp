#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maxScore(string s)
    {
        int ans = 0;
        for(int i = 0; i < s.length() - 1; i++)
        {
            int n1 = 0;
            for(int j = 0; j < i + 1; j++)
            {
                if(s[j] == '0')
                {
                    n1++;
                }
            }

            int n2 = 0;
            for(int j = i + 1; j < s.length(); j++)
            {
                if(s[j] == '1')
                {
                    n2++;
                }
            }

            ans = max(ans, n1 + n2);
        }

        return ans;
    }
};