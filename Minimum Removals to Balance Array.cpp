#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minRemoval(vector<int> &nums, int k)
    {
        int n = nums.size(), ans = n, j = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i)
        {
            while (j < n && nums[j] <= static_cast<long long>(nums[i]) * k)
            {
                j++;
            }
            ans = min(ans, n - (j - i));
        }

        return ans;
    }
};