#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries)
    {
        int n = heights.size(), q = queries.size();
        vector<int> ans(q, -1);
        vector<pair<int, int>> index;

        for(int i = 0; i < q; i++)
        {
            int &x = queries[i][0], &y = queries[i][1];
            if(x > y)
            {
                swap(x, y);
            }
            if(x == y || heights[x] < heights[y])
            {
                ans[i] = y;
            }
            else
            {
                index.emplace_back(y, i);
            }
        }

        sort(index.begin(), index.end(), greater<>());
        vector<pair<int, int>> st;

        int t = n - 1;
        for(auto i : index)
        {
            while(t > queries[i.second][1])
            {
                while(!st.empty() && heights[st.back().second] < heights[t])
                {
                    st.pop_back();
                }
                st.emplace_back(heights[t], t);
                t--;
            }

            auto it = upper_bound(st.rbegin(), st.rend(), make_pair(heights[queries[i.second][0]], n));
            ans[i.second] = (it == st.rend()) ? -1 : it -> second;
        }

        return ans;
    }
};