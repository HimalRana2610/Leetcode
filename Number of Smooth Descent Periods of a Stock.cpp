#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long getDescentPeriods(vector<int> &prices)
    {
        long long cnt = 1, ans = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] == prices[i - 1] - 1)
            {
                cnt++;
            }
            else
            {
                ans += (cnt * (cnt + 1)) / 2;
                cnt = 1;
            }
        }
        ans += (cnt * (cnt + 1)) / 2;

        return ans;
    }
};