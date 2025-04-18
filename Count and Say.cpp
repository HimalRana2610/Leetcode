#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string countAndSay(int n)
    {
        if(n == 1)
        {
            return "1";
        }

        string prev = countAndSay(n - 1), ans = "";
        int cnt = 1;

        for(int i = 1; i < prev.size(); i++)
        {
            if(prev[i] == prev[i - 1])
            {
                cnt++;
            }
            else
            {
                ans += to_string(cnt) + prev[i - 1];
                cnt = 1;
            }
        }
        ans += to_string(cnt) + prev.back();

        return ans;
    }
};