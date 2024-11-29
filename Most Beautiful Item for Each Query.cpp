#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries)
    {
        sort(items.begin(), items.end(), [](const vector<int> &a, const vector<int> &b){return a[1] < b[1];});
        vector<int> ans(queries.size(), 0);
        for(int i = 0; i < queries.size(); i++)
        {
            for(int j = items.size() - 1; j >= 0; j--)
            {
                if(items[j][0] <= queries[i])
                {
                    ans[i] = items[j][1];
                    break;
                }
            }
        }
        return ans;
    }
};