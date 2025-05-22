#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxRemoval(vector<int> &nums, vector<vector<int>> &queries)
    {
        sort(queries.begin(), queries.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]; });

        int n = nums.size(), op = 0;
        priority_queue<int> pq;
        vector<int> deleted(n + 1, 0);

        for (int i = 0, j = 0; i < n; i++)
        {
            op += deleted[i];
            while (j < queries.size() && queries[j][0] == i)
            {
                pq.push(queries[j++][1]);
            }

            while (op < nums[i] && !pq.empty() && pq.top() >= i)
            {
                op++;
                deleted[pq.top() + 1] -= 1;
                pq.pop();
            }

            if (op < nums[i])
            {
                return -1;
            }
        }

        return pq.size();
    }
};