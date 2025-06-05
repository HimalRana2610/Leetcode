#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        int n = edges1.size(), m = edges2.size();
        vector<vector<int>> tree1(n + 1), tree2(m + 1);

        for (int i = 0; i < n; i++)
        {
            int u = edges1[i][0], v = edges1[i][1];
            tree1[u].push_back(v);
            tree1[v].push_back(u);
        }

        for (int i = 0; i < m; i++)
        {
            int u = edges2[i][0], v = edges2[i][1];
            tree2[u].push_back(v);
            tree2[v].push_back(u);
        }

        vector<int> cnt1(n + 1, 0), cnt2(m + 1, 0);
        vector<int> dist1(n + 1, -1);
        dist1[0] = 0;

        queue<int> q1;
        q1.push(0);

        int even1 = 0, odd1 = 0;
        while (!q1.empty())
        {
            int node = q1.front();
            q1.pop();

            if (dist1[node] % 2 == 0)
            {
                even1++;
            }
            else
            {
                odd1++;
            }

            for (int neighbour : tree1[node])
            {
                if (dist1[neighbour] == -1)
                {
                    dist1[neighbour] = dist1[node] + 1;
                    q1.push(neighbour);
                }
            }
        }

        for (int i = 0; i <= n; i++)
        {
            cnt1[i] = (dist1[i] % 2 == 0) ? even1 : odd1;
        }

        vector<int> dist2(m + 1, -1);
        dist2[0] = 0;

        queue<int> q2;
        q2.push(0);

        int even2 = 0, odd2 = 0;
        while (!q2.empty())
        {
            int node = q2.front();
            q2.pop();

            if (dist2[node] % 2 == 0)
            {
                even2++;
            }
            else
            {
                odd2++;
            }

            for (int neighbour : tree2[node])
            {
                if (dist2[neighbour] == -1)
                {
                    dist2[neighbour] = dist2[node] + 1;
                    q2.push(neighbour);
                }
            }
        }

        int target2 = max(even2, odd2);
        vector<int> ans(n + 1);

        for (int i = 0; i <= n; i++)
        {
            ans[i] = cnt1[i] + target2;
        }

        return ans;
    }
};