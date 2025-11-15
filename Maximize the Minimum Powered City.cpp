#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_possible(vector<long long> &freq, long long x, int k, int n, int r)
    {
        vector<long long> diff = freq;
        long long sum = 0, rem = k;

        for (int i = 0; i < n; i++)
        {
            sum += diff[i];
            if (sum < x)
            {
                long long need = x - sum;
                if (need > rem)
                {
                    return false;
                }

                rem -= need;
                diff[min(n, i + 2 * r + 1)] -= need;
                sum += need;
            }
        }

        return true;
    }

    long long maxPower(vector<int> &stations, int r, int k)
    {
        int n = stations.size();
        vector<long long> freq(n + 1);

        for (int i = 0; i < n; i++)
        {
            freq[max(0, i - r)] += stations[i];
            freq[min(n, i + r + 1)] -= stations[i];
        }

        long long low = *min_element(stations.begin(), stations.end()), high = accumulate(stations.begin(), stations.end(), 0LL) + k, ans = 0;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (is_possible(freq, mid, k, n, r))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};