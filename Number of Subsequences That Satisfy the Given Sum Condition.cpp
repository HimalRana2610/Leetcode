#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> power2(n, 1);

        for (int i = 1; i < n; i++)
        {
            power2[i] = (power2[i - 1] * 2) % 1000000007;
        }

        sort(nums.begin(), nums.end());

        int left = 0, right = nums.size() - 1, ans = 0;
        while (left <= right)
        {
            if (nums[left] + nums[right] <= target)
            {
                ans = (ans + power2[right - (left++)]) % 1000000007;
            }
            else
            {
                right--;
            }
        }

        return ans;
    }
};