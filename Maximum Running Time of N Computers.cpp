#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxRunTime(int n, vector<int> &batteries)
    {
        long long left = 1, right = accumulate(batteries.begin(), batteries.end(), 0LL) / n, ans = 0;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2, total = 0;
            for (int i = 0; i < batteries.size(); i++)
            {
                total += min(static_cast<long long>(batteries[i]), mid);
            }

            if (total >= mid * n)
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ans;
    }
};