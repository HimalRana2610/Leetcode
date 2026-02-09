#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxSumTrionic(vector<int> &nums)
    {
        int n = nums.size();
        long long ans = LLONG_MIN;

        for (int i = 0; i < n; i++)
        {
            int j = i + 1;

            while (j < n && nums[j - 1] < nums[j])
            {
                j++;
            }

            int p = j - 1;
            if (p == i)
            {
                continue;
            }

            long long current = nums[p] + nums[p - 1];
            while (j < n && nums[j - 1] > nums[j])
            {
                current += nums[j++];
            }

            int q = j - 1;
            if (q == p || q == n - 1 || (nums[j] <= nums[q]))
            {
                i = q;
                continue;
            }

            current += nums[q + 1];
            long long m = 0, sum = 0;

            for (int k = q + 2; k < n && nums[k] > nums[k - 1]; k++)
            {
                sum += nums[k];
                m = max(m, sum);
            }

            current += m;
            m = 0;
            sum = 0;

            for (int k = p - 2; k >= i; k--)
            {
                sum += nums[k];
                m = max(m, sum);
            }

            current += m;
            ans = max(ans, current);
            i = q - 1;
        }

        return ans;
    }
};