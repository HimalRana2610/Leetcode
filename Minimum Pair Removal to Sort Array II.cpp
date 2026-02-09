#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumPairRemoval(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
        {
            return 0;
        }

        vector<long long> arr(nums.begin(), nums.end());
        vector<bool> removed(n, false);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        int sorted = 0;
        for (int i = 1; i < n; i++)
        {
            pq.push({arr[i - 1] + arr[i], i - 1});
            if (arr[i] >= arr[i - 1])
            {
                sorted++;
            }
        }

        if (sorted == n - 1)
        {
            return 0;
        }

        int rem = n;
        vector<int> prev(n), next(n);

        for (int i = 0; i < n; i++)
        {
            prev[i] = i - 1;
            next[i] = i + 1;
        }

        while (rem > 1)
        {
            long long sum = pq.top().first;
            int left = pq.top().second;
            pq.pop();

            int right = next[left];
            if (right >= n || removed[left] || removed[right] || arr[left] + arr[right] != sum)
            {
                continue;
            }

            if (arr[left] <= arr[right])
            {
                sorted--;
            }

            if (prev[left] != -1 && arr[prev[left]] <= arr[left])
            {
                sorted--;
            }
            if (next[right] != n && arr[right] <= arr[next[right]])
            {
                sorted--;
            }

            arr[left] += arr[right];
            removed[right] = true;
            rem--;

            if (prev[left] != -1)
            {
                pq.push({arr[prev[left]] + arr[left], prev[left]});
                if (arr[prev[left]] <= arr[left])
                {
                    sorted++;
                }
            }

            if (next[right] == n)
            {
                next[left] = n;
            }
            else
            {
                prev[next[right]] = left;
                next[left] = next[right];
                pq.push({arr[left] + arr[next[right]], left});

                if (arr[left] <= arr[next[right]])
                {
                    sorted++;
                }
            }

            if (sorted == rem - 1)
            {
                return n - rem;
            }
        }

        return n;
    }
};