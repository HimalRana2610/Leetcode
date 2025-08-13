#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        int n = fruits.size(), ans = 0;
        vector<bool> empty(n, true);

        for (int i = 0; i < n; i++)
        {
            bool found = false;
            for (int j = 0; j < n; j++)
            {
                if (empty[j] && baskets[j] >= fruits[i])
                {
                    empty[j] = false;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                ans++;
            }
        }

        return ans;
    }
};