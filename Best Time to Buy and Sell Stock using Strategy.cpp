#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxProfit(vector<int> &prices, vector<int> &strategy, int k)
    {
        int n = prices.size();
        vector<long long> prefix0(n + 1, 0), prefix1(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            prefix0[i + 1] = prefix0[i] + prices[i];
            prefix1[i + 1] = prefix1[i] + (prices[i] * strategy[i]);
        }

        long long ans = prefix1[n];
        for (int i = 0; i <= n - k; i++)
        {
            ans = max(ans, prefix1[i] - prefix1[0] + prefix0[i + k] - prefix0[i + (k / 2)] + prefix1[n] - prefix1[i + k]);
        }

        return ans;
    }
};