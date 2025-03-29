#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int minimumIndex(vector<int>& nums)
    {
        int n = nums.size(), m = 0, mf = 0;
        unordered_map<int, int> freq;

        for(int i = 0; i < n; i++)
        {
            if(++freq[nums[i]] > mf)
            {
                mf = freq[nums[i]];
                m = nums[i];
            }
        }

        vector<int> prefix(n + 1, 0);
        for(int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + (nums[i] == m);
        }

        int ans = -1;
        for(int i = 0; i < n; i++)
        {
            if(prefix[i + 1] > (i + 1) / 2 && mf - prefix[i + 1] > (n - i - 1) / 2)
            {
                ans = i;
                break;
            }
        }

        return ans;
    }
};