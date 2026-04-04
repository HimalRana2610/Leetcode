#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxWalls(vector<int> &robots, vector<int> &distance, vector<int> &walls)
    {
        int n = robots.size();
        unordered_map<int, int> dist;

        for (int i = 0; i < n; i++)
        {
            dist[robots[i]] = distance[i];
        }

        int left_pos, right_pos;
        vector<int> left(n, 0), right(n, 0), num(n, 0);

        sort(robots.begin(), robots.end());
        sort(walls.begin(), walls.end());

        for (int i = 0; i < n; i++)
        {
            int pos1 = upper_bound(walls.begin(), walls.end(), robots[i]) - walls.begin();
            if (i >= 1)
            {
                left_pos = lower_bound(walls.begin(), walls.end(), max(robots[i] - dist[robots[i]], robots[i - 1] + 1)) - walls.begin();
            }
            else
            {
                left_pos = lower_bound(walls.begin(), walls.end(), robots[i] - dist[robots[i]]) - walls.begin();
            }

            left[i] = pos1 - left_pos;
            if (i < n - 1)
            {
                right_pos = upper_bound(walls.begin(), walls.end(), min(robots[i] + dist[robots[i]], robots[i + 1] - 1)) - walls.begin();
            }
            else
            {
                right_pos = upper_bound(walls.begin(), walls.end(), robots[i] + dist[robots[i]]) - walls.begin();
            }

            int pos2 = lower_bound(walls.begin(), walls.end(), robots[i]) - walls.begin();
            right[i] = right_pos - pos2;

            if (i == 0)
            {
                continue;
            }

            int pos3 = lower_bound(walls.begin(), walls.end(), robots[i - 1]) - walls.begin();
            num[i] = pos1 - pos3;
        }

        int sub_left = left[0], sub_right = right[0], current_left, current_right;
        for (int i = 1; i < n; i++)
        {
            current_left = max(sub_left + left[i], sub_right - right[i - 1] + min(left[i] + right[i - 1], num[i]));
            current_right = max(sub_left + right[i], sub_right + right[i]);
            sub_left = current_left;
            sub_right = current_right;
        }

        return max(sub_left, sub_right);
    }
};