#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        vector<bool> has_secret(n, false);
        has_secret[0] = true;
        has_secret[firstPerson] = true;

        sort(meetings.begin(), meetings.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[2] < b[2]; });

        int m = meetings.size();
        for (int i = 0; i < m;)
        {
            int time = meetings[i][2];
            vector<pair<int, int>> batch;

            while (i < m && meetings[i][2] == time)
            {
                batch.push_back({meetings[i][0], meetings[i][1]});
                i++;
            }

            unordered_map<int, vector<int>> g;
            for (int j = 0; j < batch.size(); j++)
            {
                g[batch[j].first].push_back(batch[j].second);
                g[batch[j].second].push_back(batch[j].first);
            }

            queue<int> q;
            for (auto &kv : g)
            {
                if (has_secret[kv.first])
                {
                    q.push(kv.first);
                }
            }

            while (!q.empty())
            {
                int u = q.front();
                q.pop();

                for (int v : g[u])
                {
                    if (!has_secret[v])
                    {
                        has_secret[v] = true;
                        q.push(v);
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (has_secret[i])
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};