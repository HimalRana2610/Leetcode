#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries)
    {
        vector<int> arr(1, 0);
        for(int i = 1, j = 0; i < nums.size(); i++)
        {
            if((nums[i] % 2) == (nums[i - 1] % 2))
            {
                j++;
            }
            arr.push_back(j);
        }

        vector<bool> ans(queries.size());
        for(int i = 0; i < queries.size(); i++)
        {
            ans[i] = (arr[queries[i][0]] == arr[queries[i][1]]);
        }

        return ans;
    }
};