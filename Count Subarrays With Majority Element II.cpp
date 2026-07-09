#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countMajoritySubarrays(vector<int> &nums, int target)
    {
        int n = nums.size(), cnt = n;
        vector<int> prefix(2 * n + 1, 0);
        prefix[n] = 1;

        long long sum = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                sum += prefix[cnt++];
                prefix[cnt]++;
            }
            else
            {
                sum -= prefix[--cnt];
                prefix[cnt]++;
            }

            ans += sum;
        }

        return ans;
    }
};