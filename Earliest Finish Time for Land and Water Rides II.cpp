#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &firstStartTime, vector<int> &firstDuration, vector<int> &secondStartTime, vector<int> &secondDuration)
    {
        int firstFinishTime = INT_MAX;
        for (int i = 0; i < firstStartTime.size(); i++)
        {
            firstFinishTime = min(firstFinishTime, firstStartTime[i] + firstDuration[i]);
        }

        int secondFinishTime = INT_MAX;
        for (int i = 0; i < secondStartTime.size(); i++)
        {
            secondFinishTime = min(secondFinishTime, max(secondStartTime[i], firstFinishTime) + secondDuration[i]);
        }

        return secondFinishTime;
    }

    int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration, vector<int> &waterStartTime, vector<int> &waterDuration)
    {
        return min(solve(landStartTime, landDuration, waterStartTime, waterDuration), solve(waterStartTime, waterDuration, landStartTime, landDuration));
    }
};