#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end());
        vector<int> ans(spells.size());

        for (int i = 0; i < spells.size(); i++)
        {
            int current = potions.size(), left = 0, right = potions.size() - 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if ((long long)spells[i] * potions[mid] >= success)
                {
                    current = mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            ans[i] = potions.size() - current;
        }

        return ans;
    }
};