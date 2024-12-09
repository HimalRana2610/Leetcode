#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<int> h(n, 0), s(n, 0), c(n, 0);
        h[0] = -prices[0];
        s[0] = c[0] = 0;

        for(int i = 1; i < n; i++)
        {
            h[i] = max(h[i - 1], c[i - 1] - prices[i]);
            s[i] = h[i - 1] + prices[i];
            c[i] = max(c[i - 1], s[i - 1]);
        }

        return max(s[n - 1], c[n - 1]);
    }
};