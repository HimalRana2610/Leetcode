#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int largestIsland(vector<vector<int>>& grid)
    {
        int n = grid.size();
        vector<vector<int>> island_id(n, vector<int>(n, -1));
        unordered_map<int, int> island_size;

        auto dfs = [&](int x, int y, int id, auto &&dfs_ref) -> int
        {
            stack<pair<int, int>> st;
            st.push({x, y});
            int size = 0;

            while(!st.empty())
            {
                int cx = st.top().first, cy = st.top().second;
                st.pop();

                if(island_id[cx][cy] != -1)
                {
                    continue;
                }

                island_id[cx][cy] = id;
                size++;

                vector<pair<int, int>> dirs = {{cx - 1, cy}, {cx + 1, cy}, {cx, cy - 1}, {cx, cy + 1}};
                for(int i = 0; i < 4; i++)
                {
                    int nx = dirs[i].first, ny = dirs[i].second;
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1 && island_id[nx][ny] == -1)
                    {
                        st.push({nx, ny});
                    }
                }
            }

            return size;
        };

        int current = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1 && island_id[i][j] == -1)
                {
                    island_size[current] = dfs(i, j, current, dfs);
                    current++;
                }
            }
        }

        int ans = 0;
        for(auto &s : island_size)
        {
            ans = max(ans, s.second);
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 0)
                {
                    unordered_set<int> adj;
                    vector<pair<int, int>> dirs = {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}};

                    for(int i = 0; i < 4; i++)
                    {
                        int nx = dirs[i].first, ny = dirs[i].second;
                        if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1)
                        {
                            adj.insert(island_id[nx][ny]);
                        }
                    }

                    int size = 1;
                    for(int x : adj)
                    {
                        size += island_size[x];
                    }

                    ans = max(ans, size);
                }
            }
        }

        return ans;
    }
};