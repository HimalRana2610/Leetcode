#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPartitions(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            int diff = (2 * prefix[i]) - prefix[n];
            if (diff % 2 == 0)
            {
                ans++;
            }
        }

        return ans;
    }
};