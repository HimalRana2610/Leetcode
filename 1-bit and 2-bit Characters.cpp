#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int n = bits.size(), last = 0;
        for (int i = 0; i < n; i++)
        {
            if (bits[i] == 1)
            {
                i++;
            }
            else
            {
                last = i;
            }
        }

        return last == n - 1;
    }
};