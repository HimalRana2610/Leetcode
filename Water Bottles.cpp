#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int ans = 0, empty = 0;
        while (numBottles)
        {
            ans += numBottles;
            empty += numBottles;
            numBottles = empty / numExchange;
            empty %= numExchange;
        }

        return ans;
    }
};