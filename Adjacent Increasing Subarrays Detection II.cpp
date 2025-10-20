#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxIncreasingSubarrays(vector<int> &nums)
    {
        int prev = 0, cnt = 1, ans = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                cnt++;
            }
            else
            {
                ans = max(ans, prev / 2);
                ans = max(ans, min(prev, cnt));
                prev = cnt;
                cnt = 1;
            }
        }

        ans = max(ans, prev / 2);
        ans = max(ans, cnt / 2);
        ans = max(ans, min(prev, cnt));

        return ans;
    }
};