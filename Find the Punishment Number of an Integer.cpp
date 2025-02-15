#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool is_possible(string sqr, int n)
    {
        if(sqr.empty() && n == 0)
        {
            return true;
        }
        if(n < 0)
        {
            return false;
        }

        for(int i = 0; i < sqr.size(); i++)
        {
            string left = sqr.substr(0, i + 1), right = sqr.substr(i + 1);
            if(is_possible(right, n - stoi(left)))
            {
                return true;
            }
        }

        return false;
    }

    int punishmentNumber(int n)
    {
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(is_possible(to_string(i * i), i))
            {
                ans += i * i;
            }
        }

        return ans;
    }
};