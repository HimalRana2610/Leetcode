#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool uniformArray(vector<int> &nums1)
    {
        int m = nums1[0];
        bool odd = false;

        for (int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] < m)
            {
                m = nums1[i];
            }
            if (nums1[i] % 2 != 0)
            {
                odd = true;
            }
        }

        return (m % 2 != 0) || (!odd);
    }
};