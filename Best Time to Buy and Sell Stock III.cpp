#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<int> fp(n, 0), sp(n, 0);

        int min_price = prices[0], max_price = prices[n - 1];
        for(int i = 1; i < n; i++)
        {
            min_price = min(min_price, prices[i]);
            fp[i] = max(fp[i - 1], prices[i] - min_price);
        }
        for(int i = n - 2; i >= 0; i--)
        {
            max_price = max(max_price, prices[i]);
            sp[i] = max(sp[i + 1], max_price - prices[i]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, fp[i] + sp[i]);
        }
        
        return ans;
    }
};