#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int longestSquareStreak(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        long long ans = -1;
        for(long long i = 0; i < nums.size(); i++)
        {
            long long n = nums[i], cnt = 1;
            for(long long j = i + 1; j < nums.size(); j++)
            {
                if(n * n == nums[j])
                {
                    cnt++;
                    n = nums[j];
                }
                else if(n * n < nums[j])
                {
                    break;
                }
            }
            ans = max(ans, cnt);
        }

        if(ans == 1)
        {
            return -1;
        }

        return (int)ans;
    }
};