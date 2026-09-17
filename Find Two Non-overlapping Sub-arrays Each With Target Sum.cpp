#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSumOfLengths(vector<int> &arr, int target)
    {
        int n = arr.size(), sum = 0;
        vector<int> left(n, INT_MAX), right(n, INT_MAX);

        unordered_map<int, int> prefix;
        prefix[0] = -1;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (prefix.find(sum - target) != prefix.end())
            {
                left[i] = i - prefix[sum - target];
            }
            if (i > 0)
            {
                left[i] = min(left[i], left[i - 1]);
            }
            prefix[sum] = i;
        }

        sum = 0;
        prefix.clear();
        prefix[0] = n;

        for (int i = n - 1; i >= 0; i--)
        {
            sum += arr[i];
            if (prefix.find(sum - target) != prefix.end())
            {
                right[i] = prefix[sum - target] - i;
            }
            if (i < n - 1)
            {
                right[i] = min(right[i], right[i + 1]);
            }
            prefix[sum] = i;
        }

        int ans = INT_MAX;
        for (int i = 0; i < n - 1; i++)
        {
            if (left[i] != INT_MAX && right[i + 1] != INT_MAX)
            {
                ans = min(ans, left[i] + right[i + 1]);
            }
        }

        if (ans == INT_MAX)
        {
            return -1;
        }

        return ans;
    }
};