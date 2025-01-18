#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2)
    {
        int xor1 = 0;
        for(int i = 0; i < nums1.size(); i++)
        {
            xor1 ^= nums1[i];
        }

        int xor2 = 0;
        for(int i = 0; i < nums2.size(); i++)
        {
            xor2 ^= nums2[i];
        }

        if((nums1.size() % 2 != 0) && (nums2.size() % 2 != 0))
        {
            return xor1 ^ xor2;
        }
        else if(nums1.size() % 2 != 0)
        {
            return xor2;
        }
        else if(nums2.size() % 2 != 0)
        {
            return xor1;
        }

        return 0;
    }
};