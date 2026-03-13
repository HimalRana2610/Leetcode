#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes)
    {
        int m = *max_element(workerTimes.begin(), workerTimes.end());
        long long low = 0, high = static_cast<long long>(m) * mountainHeight * (mountainHeight + 1) / 2, ans = 0;

        while (low <= high)
        {
            long long mid = (low + high) / 2, cnt = 0;
            for (int i = 0; i < workerTimes.size(); i++)
            {
                cnt += ((-1.0 + sqrt(1 + (mid / workerTimes[i]) * 8)) / 2 + 1e-7);
            }

            if (cnt >= mountainHeight)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};