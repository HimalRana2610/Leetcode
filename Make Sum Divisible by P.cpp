#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        int n = nums.size();
        long long sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum = (sum + nums[i]) % p;
        }

        if (sum == 0)
        {
            return 0;
        }

        unordered_map<long long, int> prefix;
        prefix[0] = -1;

        int m = n;
        long long current = 0;

        for (int i = 0; i < n; i++)
        {
            current = (current + nums[i]) % p;
            long long target = (current - sum + p) % p;

            if (prefix.find(target) != prefix.end())
            {
                m = min(m, i - prefix[target]);
            }

            prefix[current] = i;
        }

        if (m == n)
        {
            return -1;
        }

        return m;
    }
};