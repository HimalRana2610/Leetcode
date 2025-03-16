#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maximumCandies(vector<int>& candies, long long k)
    {
        int l = 1, r = *max_element(candies.begin(), candies.end()), ans = 0;
        while(l <= r)
        {
            int m = l + (r - l) / 2;
            long long c = 0;
            for(int i = 0; i < candies.size(); i++)
            {
                c += candies[i] / m;
            }

            if(c >= k)
            {
                ans = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        return ans;
    }
};