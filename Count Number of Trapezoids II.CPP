#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countTrapezoids(vector<vector<int>> &points)
    {
        int n = points.size();
        unordered_map<float, vector<float>> sti;
        unordered_map<int, vector<float>> mts;

        for (int i = 0; i < n; i++)
        {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; j++)
            {
                int x2 = points[j][0], y2 = points[j][1];
                int dx = x1 - x2, dy = y1 - y2;
                float k, b;

                if (x2 == x1)
                {
                    k = FLT_MAX;
                    b = x1;
                }
                else
                {
                    k = (float)(y2 - y1) / (x2 - x1);
                    b = (float)(y1 * dx - x1 * dy) / dx;
                }

                int mid = (x1 + x2) * 10000 + (y1 + y2);
                sti[k].push_back(b);
                mts[mid].push_back(k);
            }
        }

        int ans = 0;
        for (auto &s : sti)
        {
            if (s.second.size() == 1)
            {
                continue;
            }

            map<float, int> cnt;
            for (float b : s.second)
            {
                cnt[b]++;
            }

            int sum = 0;
            for (auto &c : cnt)
            {
                ans += sum * c.second;
                sum += c.second;
            }
        }

        for (auto &m : mts)
        {
            if (m.second.size() == 1)
            {
                continue;
            }

            map<float, int> cnt;
            for (float k : m.second)
            {
                cnt[k]++;
            }

            int sum = 0;
            for (auto &c : cnt)
            {
                ans -= sum * c.second;
                sum += c.second;
            }
        }

        return ans;
    }
};