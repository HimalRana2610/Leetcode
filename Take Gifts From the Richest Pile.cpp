#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long pickGifts(vector<int>& gifts, int k)
    {
        sort(gifts.begin(), gifts.end(), greater<int>());
        for(int i = 0; i < k; i++)
        {
            int t = sqrt(gifts[0]);
            gifts[0] = t;
            sort(gifts.begin(), gifts.end(), greater<int>());
        }

        long long ans = 0;
        for(int i = 0; i < gifts.size(); i++)
        {
            ans += gifts[i];
        }
        return ans;
    }
};