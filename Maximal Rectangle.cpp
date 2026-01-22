#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<int> height(m, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                {
                    height[j]++;
                }
                else
                {
                    height[j] = 0;
                }
            }

            stack<int> s;
            vector<int> left(m), right(m);

            for (int i = 0; i < m; i++)
            {
                while (!s.empty() && height[s.top()] >= height[i])
                {
                    s.pop();
                }

                left[i] = s.empty() ? -1 : s.top();
                s.push(i);
            }

            while (!s.empty())
            {
                s.pop();
            }

            for (int i = m - 1; i >= 0; i--)
            {
                while (!s.empty() && height[s.top()] >= height[i])
                {
                    s.pop();
                }

                right[i] = s.empty() ? m : s.top();
                s.push(i);
            }

            for (int i = 0; i < m; i++)
            {
                int area = height[i] * (right[i] - left[i] - 1);
                ans = max(ans, area);
            }
        }

        return ans;
    }
};