#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration, vector<int> &waterStartTime, vector<int> &waterDuration)
    {
        int ans = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++)
        {
            for (int j = 0; j < waterStartTime.size(); j++)
            {
                int landFinishTime = landStartTime[i] + landDuration[i], waterFinishTime = waterStartTime[j] + waterDuration[j];
                if (waterStartTime[j] > landFinishTime)
                {
                    ans = min(ans, waterFinishTime);
                }
                else
                {
                    ans = min(ans, landFinishTime + waterDuration[j]);
                }

                if (landStartTime[i] > waterFinishTime)
                {
                    ans = min(ans, landFinishTime);
                }
                else
                {
                    ans = min(ans, waterFinishTime + landDuration[i]);
                }
            }
        }

        return ans;
    }
};