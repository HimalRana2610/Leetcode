#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int ans = 0;
        while (true)
        {
            if (numBottles < numExchange)
            {
                ans += numBottles;
                break;
            }
            else
            {
                ans += numExchange;
                numBottles = numBottles - numExchange + 1;
                numExchange++;
            }
        }

        return ans;
    }
};