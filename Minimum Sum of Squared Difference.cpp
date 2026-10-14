#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(int mid, vector<int> &nums1, int k)
    {
        long long sum = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            sum += nums1[i] > mid ? nums1[i] - mid : 0;
        }

        return sum <= k;
    }

    long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1, int k2)
    {
        int n = nums1.size(), k = k1 + k2, m = 0, res = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            nums1[i] = abs(nums1[i] - nums2[i]);
            m = max(m, nums1[i]);
        }

        int left = 0, right = m;
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (check(mid, nums1, k))
            {
                right = mid - 1;
                res = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (nums1[i] > res)
            {
                k -= (nums1[i] - res);
            }
        }

        sort(nums1.begin(), nums1.end(), greater<int>());

        for (int i = 0; i < n; i++)
        {
            long long diff = res >= nums1[i] ? nums1[i] : res;
            if (k && diff)
            {
                diff--;
                k--;
            }
            ans += diff * diff;
        }

        return ans;
    }
};