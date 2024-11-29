#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int minimumMountainRemovals(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> l(n, 0), r(n, 0), s;
        s.push_back(nums[0]);

        for(int i = 1; i < n; i++)
        {
            int x = lower_bound(s.begin(), s.end(), nums[i]) - s.begin();
            if(x == s.size())
            {
                s.push_back(nums[i]);
            }
            else
            {
                s[x] = nums[i];
            }
            l[i] = i + 1 - s.size();
        }

        s.clear();
        s.push_back(nums[n - 1]);

        for(int i = n - 2; i >= 0; i--)
        {
            int x = lower_bound(s.begin(), s.end(), nums[i]) - s.begin();
            if(x == s.size())
            {
                s.push_back(nums[i]);
            }
            else
            {
                s[x] = nums[i];
            }
            r[i] = n - i - s.size();
        }

        int ans = n;
        for(int i = 0; i < n; i++)
        {
            if(i + 1 - l[i] >= 2 && n - i - r[i] >= 2)
            {
                ans = min(ans, l[i] + r[i]);
            }
        }

        return ans;
    }
};