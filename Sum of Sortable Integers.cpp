#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool kmp(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size(), j = 0;
        vector<int> pi(m, 0);

        for (int i = 1; i < m; i++)
        {
            while (j > 0 && nums2[i] != nums2[j])
            {
                j = pi[j - 1];
            }

            if (nums2[i] == nums2[j])
            {
                j++;
            }

            pi[i] = j;
        }

        j = 0;
        for (int i = 0; i < n; i++)
        {
            while (j > 0 && nums1[i] != nums2[j])
            {
                j = pi[j - 1];
            }

            if (nums1[i] == nums2[j])
            {
                j++;
            }
            if (j == m)
            {
                return true;
            }
        }

        return false;
    }

    bool is_valid(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> doubled = nums1;
        doubled.insert(doubled.end(), nums1.begin(), nums1.end());
        return kmp(doubled, nums2);
    }

    int sortableIntegers(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> factor;

        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                factor.push_back(i);
                if (n / i != i)
                {
                    factor.push_back(n / i);
                }
            }
        }

        vector<int> target = nums;
        sort(target.begin(), target.end());

        int ans = 0;
        for (int i = 0; i < factor.size(); i++)
        {
            bool flag = true;
            for (int left = 0; left < n; left += factor[i])
            {
                int right = left + factor[i] - 1;
                vector<int> sub1(nums.begin() + left, nums.begin() + right + 1);
                vector<int> sub2(target.begin() + left, target.begin() + right + 1);

                if (!is_valid(sub1, sub2))
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                ans += factor[i];
            }
        }

        return ans;
    }
};