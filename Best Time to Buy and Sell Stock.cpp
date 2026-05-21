#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            suffix[i] = max(suffix[i + 1], prices[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, suffix[i] - prices[i]);
        }

        return ans;
    }
};