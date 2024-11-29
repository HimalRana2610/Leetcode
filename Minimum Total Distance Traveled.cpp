#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
    {
        int n = robot.size();
        int m = factory.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 1e18));
        dp[0][0] = 0;

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        for(int j = 0; j < m; ++j)
        {
            int position = factory[j][0];
            int maxRobots = factory[j][1];

            for(int i = 0; i <= n; ++i)
            {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);

                long long distanceSum = 0;
                for(int k = 1; k <= maxRobots && i + k <= n; ++k)
                {
                    distanceSum += abs(robot[i + k - 1] - position);
                    long long newDistance = dp[i][j] + distanceSum;

                    if(newDistance < 1e18)
                    {
                        dp[i + k][j + 1] = min(dp[i + k][j + 1], newDistance);
                    }
                }
            }
        }

        return dp[n][m] >= 1e18 ? -1 : dp[n][m];
    }
};