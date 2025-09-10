#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfPairs(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1]; });

        int n = points.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (points[i][0] <= points[j][0] && points[i][1] >= points[j][1])
                {
                    bool flag = true;
                    for (int k = i + 1; k < j; k++)
                    {
                        if (points[k][0] >= points[i][0] && points[k][0] <= points[j][0] && points[k][1] <= points[i][1] && points[k][1] >= points[j][1])
                        {
                            flag = false;
                            break;
                        }
                    }

                    if (flag)
                    {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};