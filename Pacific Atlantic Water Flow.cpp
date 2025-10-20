#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &ocean, int i, int j, int m, int n)
    {
        if (ocean[i][j])
        {
            return;
        }

        ocean[i][j] = true;
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int d = 0; d < 4; d++)
        {
            int x = i + dirs[d].first, y = j + dirs[d].second;
            if (x >= 0 && x < m && y >= 0 && y < n && heights[x][y] >= heights[i][j])
            {
                dfs(heights, ocean, x, y, m, n);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false)), atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            dfs(heights, pacific, i, 0, m, n);
            dfs(heights, atlantic, i, n - 1, m, n);
        }
        for (int j = 0; j < n; j++)
        {
            dfs(heights, pacific, 0, j, m, n);
            dfs(heights, atlantic, m - 1, j, m, n);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};