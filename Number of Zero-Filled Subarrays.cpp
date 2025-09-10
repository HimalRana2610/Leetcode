#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long ans = 0, cnt = (nums[0] == 0) ? 1 : 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == 0 && nums[i - 1] == 0)
            {
                cnt++;
            }
            else
            {
                ans += (cnt * (cnt + 1)) / 2;
                if (nums[i] == 0)
                {
                    cnt = 1;
                }
                else
                {
                    cnt = 0;
                }
            }
        }
        ans += (cnt * (cnt + 1)) / 2;

        return ans;
    }
};