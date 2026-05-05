#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0), current = 0;
        for (int i = 0; i < n; i++)
        {
            current += i * nums[i];
        }

        int ans = current;
        for (int i = 1; i < n; i++)
        {
            current += sum - n * nums[n - i];
            ans = max(ans, current);
        }

        return ans;
    }
};