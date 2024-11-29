#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls)
    {
        vector<vector<int>> guarded(m, vector<int>(n, 0));
        for(auto &g : guards)
        {
            guarded[g[0]][g[1]] = 2;
        }
        for(auto &w : walls)
        {
            guarded[w[0]][w[1]] = 2;
        }

        vector<int> dir = {-1, 0, 1, 0, -1};
        for(auto &g : guards)
        {
            for(int k = 0; k < 4; k++)
            {
                int i = g[0], j = g[1];
                while(i + dir[k] >= 0 && i + dir[k] < m && j + dir[k + 1] >= 0 && j + dir[k + 1] < n && guarded[i + dir[k]][j + dir[k + 1]] < 2)
                {
                    i += dir[k];
                    j += dir[k + 1];
                    guarded[i][j] = 1;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            ans += count(guarded[i].begin(), guarded[i].begin() + n, 0);
        }
        return ans;
    }
};