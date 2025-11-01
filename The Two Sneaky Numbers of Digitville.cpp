#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> found(n, false);

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (found[nums[i]])
            {
                ans.push_back(nums[i]);
            }
            else
            {
                found[nums[i]] = true;
            }
        }

        return ans;
    }
};