#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> digit_sum(n);

        for (int i = 0; i < n; i++)
        {
            int x = nums[i], sum = 0;
            while (x > 0)
            {
                sum += x % 10;
                x /= 10;
            }
            digit_sum[i] = sum;
        }

        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), indices.end(), [&](int a, int b)
             { return digit_sum[a] != digit_sum[b] ? digit_sum[a] < digit_sum[b] : nums[a] < nums[b]; });

        vector<int> target(n);
        for (int i = 0; i < n; i++)
        {
            target[indices[i]] = i;
        }

        int cycles = 0;
        vector<int> visited(n);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                int j = i;
                cycles++;

                while (!visited[j])
                {
                    visited[j] = true;
                    j = target[j];
                }
            }
        }

        return n - cycles;
    }
};