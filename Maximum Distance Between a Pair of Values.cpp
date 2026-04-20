#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size(), ans = 0, i = 0, j = 0;
        while (i < n && j < m)
        {
            if (i > j)
            {
                j = i;
            }

            if (j >= m)
            {
                break;
            }

            if (nums1[i] <= nums2[j])
            {
                ans = max(ans, j - i);
                j++;
            }
            else
            {
                i++;
            }
        }

        return ans;
    }
};