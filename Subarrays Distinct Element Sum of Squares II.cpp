#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumCounts(vector<int> &nums)
    {
        int n = nums.size();
        long long ans = 0;
        vector<long long> cnt(n + 1), total(n + 1);
        unordered_map<int, int> last;

        for (int r = 0; r < n; r++)
        {
            int p = last.count(nums[r]) ? last[nums[r]] : -1;
            long long c = 0, s = 0;

            for (int i = n - p - 1; i > 0; i -= i & -i)
            {
                c += cnt[i], s += total[i];
            }

            long long gain = (long long)(r - p) * (r - p) - 2 * (s - p * c);
            ans = (ans + (n - r) * gain) % 1000000007;

            for (int i = n - p; i <= n; i += i & -i)
            {
                cnt[i]++, total[i] += p;
            }

            last[nums[r]] = r;
        }

        return ans;
    }
};