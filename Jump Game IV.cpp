#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
        {
            return 0;
        }

        unordered_map<int, vector<int>> idx;
        for (int i = 0; i < n; i++)
        {
            idx[arr[i]].push_back(i);
        }

        vector<bool> visited(n, false);
        visited[0] = true;

        queue<int> q;
        q.push(0);

        int ans = 0;
        while (!q.empty())
        {
            int l = q.size();
            while (l--)
            {
                int node = q.front();
                q.pop();

                if (node == n - 1)
                {
                    return ans;
                }

                if (node - 1 >= 0 && !visited[node - 1])
                {
                    visited[node - 1] = true;
                    q.push(node - 1);
                }

                if (node + 1 < n && !visited[node + 1])
                {
                    visited[node + 1] = true;
                    q.push(node + 1);
                }

                for (int neighbour : idx[arr[node]])
                {
                    if (!visited[neighbour])
                    {
                        visited[neighbour] = true;
                        q.push(neighbour);
                    }
                }

                idx.erase(arr[node]);
            }

            ans++;
        }

        return ans;
    }
};