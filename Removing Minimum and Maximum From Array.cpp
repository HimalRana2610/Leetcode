#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int n = nums.size(), mn = INT_MAX, mni = -1, mx = INT_MIN, mxi = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < mn)
            {
                mn = nums[i];
                mni = i;
            }
            if (nums[i] > mx)
            {
                mx = nums[i];
                mxi = i;
            }
        }

        if (mni > mxi)
        {
            swap(mni, mxi);
        }

        return min({mxi + 1, n - mni, mni + 1 + n - mxi});
    }
};