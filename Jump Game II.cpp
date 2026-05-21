#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size(), ans = 0;
        vector<bool> visited(n, false);
        visited[0] = true;

        queue<int> q;
        q.push(0);

        while (!q.empty())
        {
            int l = q.size();
            while (l--)
            {
                int i = q.front();
                q.pop();

                if (i == n - 1)
                {
                    return ans;
                }

                for (int j = 0; j <= nums[i] && i + j < n; j++)
                {
                    if (!visited[i + j])
                    {
                        visited[i + j] = true;
                        q.push(i + j);
                    }
                }
            }
            ans++;
        }

        return ans;
    }
};