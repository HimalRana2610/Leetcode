#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maxCount(vector<int>& banned, int n, int maxSum)
    {
        unordered_set<int> ban(banned.begin(), banned.end());
        int sum = 0, ans = 0;

        for(int i = 1; i <= n; i++)
        {
            if(ban.find(i) == ban.end())
            {
                sum += i;
                if(sum > maxSum)
                {
                    break;
                }
                ans++;
            }
        }

        return ans;
    }
};