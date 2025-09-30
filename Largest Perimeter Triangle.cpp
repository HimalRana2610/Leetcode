#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        sort(nums.rbegin(), nums.rend());
        int n = nums.size(), ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (nums[i] < nums[j] + nums[k])
                    {
                        ans = nums[i] + nums[j] + nums[k];
                        return ans;
                    }
                }
            }
        }

        return ans;
    }
};