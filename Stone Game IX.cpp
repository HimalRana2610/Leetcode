#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool stoneGameIX(vector<int> &stones)
    {
        int zero = 0, one = 0, two = 0;
        for (int i = 0; i < stones.size(); i++)
        {
            if (stones[i] % 3 == 0)
            {
                zero++;
            }
            else if (stones[i] % 3 == 1)
            {
                one++;
            }
            else
            {
                two++;
            }
        }

        if (zero % 2 == 0)
        {
            return one >= 1 && two >= 1;
        }

        return one - two > 2 || two - one > 2;
    }
};