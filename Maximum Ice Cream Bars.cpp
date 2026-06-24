#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        vector<int> freq(*max_element(costs.begin(), costs.end()) + 1, 0);
        for (int i = 0; i < costs.size(); i++)
        {
            freq[costs[i]]++;
        }

        int ans = 0;
        for (int i = 0; i < freq.size() && coins > 0; i++)
        {
            if ((long long)i * freq[i] > coins)
            {
                ans += coins / i;
                break;
            }

            ans += freq[i];
            coins -= (long long)i * freq[i];
        }

        return ans;
    }
};