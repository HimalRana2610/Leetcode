#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        int n = nums.size(), ans = 0, current = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0)
            {
                current++;
            }
        }
        ans = max(ans, current);

        current = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 != 0)
            {
                current++;
            }
        }
        ans = max(ans, current);

        current = 0;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (flag && nums[i] % 2 == 0)
            {
                current++;
                flag = !flag;
            }
            else if (!flag && nums[i] % 2 != 0)
            {
                current++;
                flag = !flag;
            }
        }
        ans = max(ans, current);

        current = 0;
        flag = true;
        for (int i = 0; i < n; i++)
        {
            if (flag && nums[i] % 2 != 0)
            {
                current++;
                flag = !flag;
            }
            else if (!flag && nums[i] % 2 == 0)
            {
                current++;
                flag = !flag;
            }
        }
        ans = max(ans, current);

        return ans;
    }
};