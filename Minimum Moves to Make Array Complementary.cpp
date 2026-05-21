#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMoves(vector<int> &nums, int limit)
    {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++)
        {
            int a = min(nums[i], nums[n - 1 - i]), b = max(nums[i], nums[n - 1 - i]);
            diff[2] += 2;
            diff[a + 1] -= 1;
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
            diff[b + limit + 1] += 1;
        }

        int current = 0, ans = n;
        for (int i = 2; i <= 2 * limit; i++)
        {
            current += diff[i];
            ans = min(ans, current);
        }

        return ans;
    }
};