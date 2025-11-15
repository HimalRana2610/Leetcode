#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int ans = 0;
        for (int i = 0, j = 0; i < neededTime.size() && j < neededTime.size(); i = j)
        {
            int current = 0, m = 0;
            while (j < neededTime.size() && colors[i] == colors[j])
            {
                current += neededTime[j];
                m = max(m, neededTime[j++]);
            }
            ans += current - m;
        }

        return ans;
    }
};