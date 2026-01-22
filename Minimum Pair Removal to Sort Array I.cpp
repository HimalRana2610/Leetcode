#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_sorted(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] > nums[i])
            {
                return false;
            }
        }

        return true;
    }

    int minimumPairRemoval(vector<int> &nums)
    {
        int ans = 0;
        while (!is_sorted(nums))
        {
            int m = INT_MAX, idx = -1;
            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i - 1] + nums[i] < m)
                {
                    m = nums[i - 1] + nums[i];
                    idx = i - 1;
                }
            }

            vector<int> new_nums;
            for (int i = 0; i < nums.size(); i++)
            {
                if (i == idx)
                {
                    new_nums.push_back(nums[i] + nums[i + 1]);
                    i++;
                }
                else
                {
                    new_nums.push_back(nums[i]);
                }
            }

            nums = new_nums;
            ans++;
        }

        return ans;
    }
};