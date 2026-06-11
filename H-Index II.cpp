#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        int left = 0, right = n - 1, ans = 0;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (n - mid > citations[mid])
            {
                left = mid + 1;
            }
            else
            {
                ans = n - mid;
                right = mid - 1;
            }
        }

        return ans;
    }
};