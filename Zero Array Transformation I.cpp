#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<int> diff(nums.size() + 1, 0);

        for(int i = 0; i < queries.size(); i++)
        {
            diff[queries[i][0]]--;
            if (queries[i][1] + 1 < nums.size())
            {
                diff[queries[i][1] + 1]++;
            }
        }

        int currentDecrement = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            currentDecrement += diff[i];
            if(nums[i] + currentDecrement > 0)
            {
                return false;
            }
        }

        return true;
    }
};