#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries)
    {
        int m = grid.size(), n = grid[0].size(), q = queries.size();
        vector<int> ans(q, 0);
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}, sorted;

        for(int i = 0; i < q; i++)
        {
            sorted.push_back({queries[i], i});
        }

        sort(sorted.begin(), sorted.end());

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;

        int total = 0;
        for(int i = 0; i < q; i++)
        {
            int val = sorted[i].first, index = sorted[i].second;
            while(!pq.empty() && pq.top().first < val)
            {
                int current = pq.top().first;
                pair<int, int> pos = pq.top().second;
                pq.pop();

                int row = pos.first, col = pos.second;
                total++;

                for(int j = 0; j < 4; j++)
                {
                    int nr = row + dirs[j].first, nc = col + dirs[j].second;
                    if(nr >= 0 && nc >= 0 && nr < m && nc < n && !visited[nr][nc])
                    {
                        pq.push({grid[nr][nc], {nr, nc}});
                        visited[nr][nc] = true;
                    }
                }
            }
            ans[index] = total;
        }

        return ans;
    }
};