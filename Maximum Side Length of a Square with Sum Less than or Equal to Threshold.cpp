#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSideLength(vector<vector<int>> &mat, int threshold)
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                prefix[i + 1][j + 1] = mat[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];
            }
        }

        int left = 0, right = min(m, n), ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            bool found = false;

            for (int i = mid; i <= m; i++)
            {
                for (int j = mid; j <= n; j++)
                {
                    if (prefix[i][j] - prefix[i - mid][j] - prefix[i][j - mid] + prefix[i - mid][j - mid] <= threshold)
                    {
                        found = true;
                        break;
                    }
                }

                if (found)
                {
                    break;
                }
            }

            if (found)
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