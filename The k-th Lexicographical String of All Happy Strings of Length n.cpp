#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string dfs(string prefix, int l, int n, int k)
    {
        if(n == 0)
        {
            return prefix;
        }

        for(char ch = 'a'; ch <= 'c'; ch++)
        {
            if(!prefix.empty() && ch == prefix.back())
            {
                continue;
            }

            int cnt = (1 << (l - prefix.length() - 1));
            if(cnt >= k)
            {
                return dfs(prefix + ch, l, n - 1, k);
            }
            else
            {
                k -= cnt;
            }
        }

        return "";
    }

    string getHappyString(int n, int k)
    {
        return dfs("", n, n, k);
    }
};