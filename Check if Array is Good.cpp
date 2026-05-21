#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isGood(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        bool flag = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] != i + 1)
            {
                flag = false;
                break;
            }
        }

        if (!flag)
        {
            return false;
        }

        return nums[n - 1] == n - 1;
    }
};