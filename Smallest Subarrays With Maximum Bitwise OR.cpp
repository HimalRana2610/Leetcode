#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> smallestSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> last(31, -1), ans(n);

        for (int left = n - 1; left >= 0; left--)
        {
            int right = left;
            for (int i = 0; i < 31; i++)
            {
                if (!(nums[left] & (1 << i)))
                {
                    if (last[i] != -1)
                    {
                        right = max(right, last[i]);
                    }
                }
                else
                {
                    last[i] = left;
                }
            }
            ans[left] = right - left + 1;
        }

        return ans;
    }
};