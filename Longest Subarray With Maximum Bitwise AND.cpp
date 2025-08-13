#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int m = *max_element(nums.begin(), nums.end()), cnt = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == m)
            {
                cnt++;
            }
            else
            {
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        ans = max(ans, cnt);

        return ans;
    }
};