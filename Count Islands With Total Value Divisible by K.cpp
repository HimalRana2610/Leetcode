#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countIslands(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        queue<pair<int, int>> q;

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] > 0)
                {
                    visited[i][j] = true;
                    q.push({i, j});

                    long long sum = 0;
                    while (!q.empty())
                    {
                        int x = q.front().first, y = q.front().second;
                        q.pop();

                        sum += grid[x][y];
                        for (int l = 0; l < 4; l++)
                        {
                            int nx = x + dirs[l].first, ny = y + dirs[l].second;
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] > 0)
                            {
                                visited[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }

                    if (sum % k == 0)
                    {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};