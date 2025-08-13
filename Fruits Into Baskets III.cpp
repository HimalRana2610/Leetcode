#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        int n = fruits.size(), m = sqrt(fruits.size());
        int s = (n + m - 1) / m, ans = 0;

        vector<int> ma(s);
        for (int i = 0; i < n; i++)
        {
            ma[i / m] = max(ma[i / m], baskets[i]);
        }

        for (int i = 0; i < n; i++)
        {
            bool found = true;
            for (int j = 0; j < s; j++)
            {
                if (ma[j] < fruits[i])
                {
                    continue;
                }

                ma[j] = 0;
                bool flag = false;

                for (int k = 0; k < m; k++)
                {
                    int pos = j * m + k;
                    if (pos < n && baskets[pos] >= fruits[i] && !flag)
                    {
                        baskets[pos] = 0;
                        flag = true;
                    }
                    if (pos < n)
                    {
                        ma[j] = max(ma[j], baskets[pos]);
                    }
                }
                found = false;
                break;
            }

            if (found)
            {
                ans++;
            }
        }

        return ans;
    }
};