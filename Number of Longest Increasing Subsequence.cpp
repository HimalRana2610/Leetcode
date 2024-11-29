#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int findNumberOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> l(n, 1), c(n, 1);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                {
                    if(l[j] + 1 > l[i])
                    {
                        l[i] = l[j] + 1;
                        c[i] = c[j];
                    }
                    else if(l[j] + 1 == l[i])
                    {
                        c[i] += c[j];
                    }
                }
            }
        }

        int m = *max_element(l.begin(), l.end()), ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(l[i] == m)
            {
                ans += c[i];
            }
        }

        return ans;
    }
};