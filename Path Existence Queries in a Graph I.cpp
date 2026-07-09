#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
    {
        int cnt = 0;
        vector<int> component(n, 0);

        for (int i = 1; i < n; i++)
        {
            if (nums[i] - nums[i - 1] > maxDiff)
            {
                cnt++;
            }
            component[i] = cnt;
        }

        vector<bool> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            ans.push_back(component[queries[i][0]] == component[queries[i][1]]);
        }

        return ans;
    }
};