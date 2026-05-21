#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int current = prices[0], ans = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i - 1] > prices[i])
            {
                ans += prices[i - 1] - current;
                current = prices[i];
            }
        }

        return ans + prices.back() - current;
    }
};