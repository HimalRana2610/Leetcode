#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMoves(vector<string> &classroom, int energy)
    {
        int n = classroom.size(), m = classroom[0].size(), sx, sy, cnt = 0;
        vector<vector<int>> id(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (classroom[i][j] == 'S')
                {
                    sx = i;
                    sy = j;
                }
                else if (classroom[i][j] == 'L')
                {
                    id[i][j] = 1 << cnt++;
                }
            }
        }

        vector<vector<vector<int>>> best(n, vector<vector<int>>(m, vector<int>(1 << cnt, -1)));
        best[sx][sy][0] = energy;

        queue<vector<int>> q;
        q.push({sx, sy, 0, energy, 0});

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty())
        {
            int x = q.front()[0], y = q.front()[1], mask = q.front()[2], e = q.front()[3], steps = q.front()[4];
            q.pop();

            if (mask == (1 << cnt) - 1)
            {
                return steps;
            }
            if (e == 0)
            {
                continue;
            }

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dirs[i].first, ny = y + dirs[i].second;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || classroom[nx][ny] == 'X')
                {
                    continue;
                }

                int ne = classroom[nx][ny] == 'R' ? energy : e - 1, nmask = mask | id[nx][ny];
                if (ne > best[nx][ny][nmask])
                {
                    best[nx][ny][nmask] = ne;
                    q.push({nx, ny, nmask, ne, steps + 1});
                }
            }
        }

        return -1;
    }
};