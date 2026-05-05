#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &visited)
    {
        int n = grid.size(), m = grid[0].size();
        if (x == n - 1 && y == m - 1)
        {
            return true;
        }

        if (grid[x][y] == 1)
        {
            int nx = x, ny = y - 1;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && (grid[nx][ny] == 1 || grid[nx][ny] == 4 || grid[nx][ny] == 6))
            {
                visited[nx][ny] = true;
                if (dfs(nx, ny, grid, visited))
                {
                    return true;
                }
                visited[nx][ny] = false;
            }

            nx = x, ny = y + 1;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && (grid[nx][ny] == 1 || grid[nx][ny] == 3 || grid[nx][ny] == 5))
            {
                visited[nx][ny] = true;
                if (dfs(nx, ny, grid, visited))
                {
                    return true;
                }
                visited[nx][ny] = false;
            }
        }
        else if (grid[x][y] == 2)
        {
            int nx = x - 1, ny = y;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && (grid[nx][ny] == 2 || grid[nx][ny] == 3 || grid[nx][ny] == 4))
            {
                visited[nx][ny] = true;
                if (dfs(nx, ny, grid, visited))
                {
                    return true;
                }
                visited[nx][ny] = false;
            }

            nx = x + 1, ny = y;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && (grid[nx][ny] == 2 || grid[nx][ny] == 5 || grid[nx][ny] == 6))
            {
                visited[nx][ny] = true;
                if (dfs(nx, ny, grid, visited))
                {
                    return true;
                }
                visited[nx][ny] = false;
            }
        }
        else if (grid[x][y] == 3)
        {
            int nx = x, ny = y - 1;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && (grid[nx][ny] == 1 || grid[nx][ny] == 4 || grid[nx][ny] == 6))
            {
                visited[nx][ny] = true;
                if (dfs(nx, ny, grid, visited))
                {
                    return true;
                }
                visited[nx][ny] = false;
            }

            nx = x + 1, ny = y;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && (grid[nx][ny] == 2 || grid[nx][ny] == 5 || grid[nx][ny] == 6))
            {
                visited[nx][ny] = true;
                if (dfs(nx, ny, grid, visited))
                {
                    return true;
                }
                visited[nx][ny] = false;
            }
        }
        else if (grid[x][y] == 4)
        {
            int nx = x, ny = y + 1;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && (grid[nx][ny] == 1 || grid[nx][ny] == 3 || grid[nx][ny] == 5))
            {
                visited[nx][ny] = true;
                if (dfs(nx, ny, grid, visited))
                {
                    return true;
                }
                visited[nx][ny] = false;
            }

            nx = x + 1, ny = y;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && (grid[nx][ny] == 2 || grid[nx][ny] == 5 || grid[nx][ny] == 6))
            {
                visited[nx][ny] = true;
                if (dfs(nx, ny, grid, visited))
                {
                    return true;
                }
                visited[nx][ny] = false;
            }
        }
        else if (grid[x][y] == 5)
        {
            int nx = x - 1, ny = y;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && (grid[nx][ny] == 2 || grid[nx][ny] == 3 || grid[nx][ny] == 4))
            {
                visited[nx][ny] = true;
                if (dfs(nx, ny, grid, visited))
                {
                    return true;
                }
                visited[nx][ny] = false;
            }

            nx = x, ny = y - 1;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && (grid[nx][ny] == 1 || grid[nx][ny] == 4 || grid[nx][ny] == 6))
            {
                visited[nx][ny] = true;
                if (dfs(nx, ny, grid, visited))
                {
                    return true;
                }
                visited[nx][ny] = false;
            }
        }
        else
        {
            int nx = x - 1, ny = y;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && (grid[nx][ny] == 2 || grid[nx][ny] == 3 || grid[nx][ny] == 4))
            {
                visited[nx][ny] = true;
                if (dfs(nx, ny, grid, visited))
                {
                    return true;
                }
                visited[nx][ny] = false;
            }

            nx = x, ny = y + 1;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && (grid[nx][ny] == 1 || grid[nx][ny] == 3 || grid[nx][ny] == 5))
            {
                visited[nx][ny] = true;
                if (dfs(nx, ny, grid, visited))
                {
                    return true;
                }
                visited[nx][ny] = false;
            }
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        return dfs(0, 0, grid, visited);
    }
};