#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistinctElements(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int m = INT_MIN, ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int current = min(max(nums[i] - k, m + 1), nums[i] + k);
            if (current > m)
            {
                ans++;
                m = current;
            }
        }

        return ans;
    }
};