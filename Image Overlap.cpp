#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
    {
        int n = img1.size();
        vector<pair<int, int>> a, b;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (img1[i][j] == 1)
                {
                    a.push_back({i, j});
                }
                if (img2[i][j] == 1)
                {
                    b.push_back({i, j});
                }
            }
        }

        int ans = 0;
        vector<vector<int>> cnt(2 * n, vector<int>(2 * n, 0));

        for (auto &p1 : a)
        {
            for (auto &p2 : b)
            {
                int dx = p2.first - p1.first + n, dy = p2.second - p1.second + n;
                ans = max(ans, ++cnt[dx][dy]);
            }
        }

        return ans;
    }
};