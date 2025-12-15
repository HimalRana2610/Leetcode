#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPartitions(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long long> dp(n + 1), prefix(n + 1);
        dp[0] = prefix[0] = 1;

        deque<int> mi, ma;
        for (int i = 0, j = 0; i < n; i++)
        {
            while (!ma.empty() && nums[ma.back()] <= nums[i])
            {
                ma.pop_back();
            }

            ma.push_back(i);
            while (!mi.empty() && nums[mi.back()] >= nums[i])
            {
                mi.pop_back();
            }

            mi.push_back(i);
            while (!ma.empty() && !mi.empty() && nums[ma.front()] - nums[mi.front()] > k)
            {
                if (ma.front() == j)
                {
                    ma.pop_front();
                }
                if (mi.front() == j)
                {
                    mi.pop_front();
                }
                j++;
            }

            dp[i + 1] = (prefix[i] - (j > 0 ? prefix[j - 1] : 0) + 1000000007) % 1000000007;
            prefix[i + 1] = (prefix[i] + dp[i + 1]) % 1000000007;
        }

        return dp[n];
    }
};