#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool can_cross(int day, int row, int col, const vector<vector<int>> &cells)
    {
        vector<vector<bool>> grid(row, vector<bool>(col, false));
        for (int i = 0; i < day; ++i)
        {
            grid[cells[i][0] - 1][cells[i][1] - 1] = true;
        }

        queue<pair<int, int>> q;
        for (int c = 0; c < col; ++c)
        {
            if (!grid[0][c])
            {
                q.push({0, c});
                grid[0][c] = true;
            }
        }

        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty())
        {
            int r = q.front().first, c = q.front().second;
            q.pop();

            if (r == row - 1)
            {
                return true;
            }

            for (int i = 0; i < dirs.size(); i++)
            {
                int nr = r + dirs[i][0], nc = c + dirs[i][1];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col && !grid[nr][nc])
                {
                    q.push({nr, nc});
                    grid[nr][nc] = true;
                }
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        int left = 1, right = row * col, ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (can_cross(mid, row, col, cells))
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ans;
    }
};