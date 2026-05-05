#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<long long> &arr, long long side, int k, long long limit)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            long long end = arr[i] + side * 4LL - limit, current = arr[i];
            for (int j = 0; j < k - 1; j++)
            {
                auto it = lower_bound(arr.begin(), arr.end(), current + limit);
                if (it == arr.end() || *it > end)
                {
                    current = -1;
                    break;
                }
                current = *it;
            }

            if (current >= 0)
            {
                return true;
            }
        }

        return false;
    };
    int maxDistance(int side, vector<vector<int>> &points, int k)
    {
        int n = points.size();
        vector<long long> arr(n);

        for (int i = 0; i < n; i++)
        {
            int x = points[i][0], y = points[i][1];
            if (x == 0)
            {
                arr[i] = y;
            }
            else if (y == side)
            {
                arr[i] = side + x;
            }
            else if (x == side)
            {
                arr[i] = side * 3LL - y;
            }
            else
            {
                arr[i] = side * 4LL - x;
            }
        }

        sort(arr.begin(), arr.end());

        long long low = 1, high = side;
        int ans = 0;

        while (low <= high)
        {
            long long mid = (low + high) / 2;
            if (check(arr, side, k, mid))
            {
                low = mid + 1;
                ans = mid;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};