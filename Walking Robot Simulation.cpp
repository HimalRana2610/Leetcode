#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        set<pair<int, int>> s;
        for (int i = 0; i < obstacles.size(); i++)
        {
            s.insert({obstacles[i][0], obstacles[i][1]});
        }

        int x = 0, y = 0, dir = 0, ans = 0;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (int i = 0; i < commands.size(); i++)
        {
            if (commands[i] == -2)
            {
                dir = (dir + 3) % 4;
            }
            else if (commands[i] == -1)
            {
                dir = (dir + 1) % 4;
            }
            else
            {
                for (int j = 0; j < commands[i]; j++)
                {
                    int nx = x + dirs[dir][0], ny = y + dirs[dir][1];
                    if (s.find({nx, ny}) != s.end())
                    {
                        break;
                    }

                    x = nx;
                    y = ny;
                    ans = max(ans, x * x + y * y);
                }
            }
        }

        return ans;
    }
};