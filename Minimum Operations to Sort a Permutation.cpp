#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size(), start = find(nums.begin(), nums.end(), 0) - nums.begin();
        if (n == 1)
        {
            return 0;
        }

        bool asc = true, desc = true;
        for (int i = 1; i < n; i++)
        {
            if (nums[(start + i) % n] != i)
            {
                asc = false;
            }
            if (nums[(start + i) % n] != n - i)
            {
                desc = false;
            }
            if (!asc && !desc)
            {
                return -1;
            }
        }

        if (asc)
        {
            return min(start, n - start + 2);
        }

        return min(n - start, start + 2);
    }
};