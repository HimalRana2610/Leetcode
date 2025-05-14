#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long minSum(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size(), m = nums2.size(), zero1 = 0, zero2 = 0;
        long long sum1 = 0, sum2 = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums1[i] == 0)
            {
                zero1++;
            }
            else
            {
                sum1 += nums1[i];
            }
        }
        for(int i = 0; i < m; i++)
        {
            if(nums2[i] == 0)
            {
                zero2++;
            }
            else
            {
                sum2 += nums2[i];
            }
        }

        if(zero1 == 0)
        {
            if(zero2 == 0 && sum1 != sum2)
            {
                return -1;
            }
            if(sum2 > sum1)
            {
                return -1;
            }
            else if(zero2 > sum1 - sum2)
            {
                return -1;
            }
            else
            {
                return sum1;
            }
        }
        if(zero2 == 0)
        {
            if(zero1 == 0 && sum1 != sum2)
            {
                return -1;
            }
            if(sum1 > sum2)
            {
                return -1;
            }
            else if(zero1 > sum2 - sum1)
            {
                return -1;
            }
            else
            {
                return sum2;
            }
        }

        return max(sum1 + zero1, sum2 + zero2);
    }
};