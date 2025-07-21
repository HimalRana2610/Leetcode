#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]; });

        vector<pair<int, int>> ans;
        for (int i = 0; i < points.size(); i++)
        {
            if (ans.empty())
            {
                ans.push_back({points[i][0], points[i][1]});
            }
            else
            {
                bool found = false;
                for (auto &x : ans)
                {
                    if (points[i][0] <= x.second)
                    {
                        x.first = max(x.first, points[i][0]);
                        x.second = min(x.second, points[i][1]);
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    ans.push_back({points[i][0], points[i][1]});
                }
            }
        }

        return ans.size();
    }
};