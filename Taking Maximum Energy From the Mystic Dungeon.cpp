#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumEnergy(vector<int> &energy, int k)
    {
        int n = energy.size(), ans = INT_MIN;
        for (int i = n - k; i < n; i++)
        {
            int current = 0;
            for (int j = i; j >= 0; j -= k)
            {
                current += energy[j];
                ans = max(ans, current);
            }
        }

        return ans;
    }
};