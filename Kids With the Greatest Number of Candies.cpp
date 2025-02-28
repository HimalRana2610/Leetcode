#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
    {
        int n = candies.size(), m = *max_element(candies.begin(), candies.end());
        vector<bool> ans(n, false);

        for(int i = 0; i < n; i++)
        {
            if(candies[i] + extraCandies >= m)
            {
                ans[i] = true;
            }
        }

        return ans;
    }
};