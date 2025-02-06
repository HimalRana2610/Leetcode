#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long maximumTotalSum(vector<int>& maximumHeight)
    {
        int n = maximumHeight.size(), m = INT_MAX;
        sort(maximumHeight.begin(), maximumHeight.end());

        long long ans = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            if(maximumHeight[i] < m)
            {
                ans += maximumHeight[i];
                m = maximumHeight[i];
            }
            else
            {
                ans += m - 1;
                m -= 1;
            }

            if(m == 0)
            {
                return -1;
            }
        }

        return ans;
    }
};