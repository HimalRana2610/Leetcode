#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumEffort(vector<vector<int>> &tasks)
    {
        sort(tasks.begin(), tasks.end(), [&](const vector<int> &a, const vector<int> &b)
             { return a[1] - a[0] > b[1] - b[0]; });

        int r = 0, ans = 0;
        for (int i = 0; i < tasks.size(); i++)
        {
            ans += r > tasks[i][1] ? 0 : tasks[i][1] - r;
            r = max(tasks[i][1] - tasks[i][0], r - tasks[i][0]);
        }

        return ans;
    }
};