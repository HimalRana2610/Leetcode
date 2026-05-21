#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxValue(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<vector<int>> st;

        for (int i = 0; i < n; i++)
        {
            vector<int> curr = {nums[i], i, i};
            while (!st.empty() && st.back()[0] > nums[i])
            {
                vector<int> top = st.back();
                st.pop_back();
                curr[0] = max(curr[0], top[0]);
                curr[1] = top[1];
            }
            st.push_back(curr);
        }

        for (int i = 0; i < st.size(); i++)
        {
            for (int j = st[i][1]; j <= st[i][2]; j++)
            {
                ans[j] = st[i][0];
            }
        }

        return ans;
    }
};