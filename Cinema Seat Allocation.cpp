#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
    {
        unordered_map<int, vector<bool>> cinema;
        for (int i = 0; i < reservedSeats.size(); i++)
        {
            if (!cinema.count(reservedSeats[i][0]))
            {
                cinema[reservedSeats[i][0]].resize(11, true);
            }
            cinema[reservedSeats[i][0]][reservedSeats[i][1]] = false;
        }

        int ans = 2 * n;
        for (auto &r : cinema)
        {
            if (r.second[2] && r.second[3] && r.second[4] && r.second[5] && r.second[6] && r.second[7] && r.second[8] && r.second[9])
            {
                continue;
                ;
            }
            else if ((r.second[2] && r.second[3] && r.second[4] && r.second[5]) || (r.second[4] && r.second[5] && r.second[6] && r.second[7]) || (r.second[6] && r.second[7] && r.second[8] && r.second[9]))
            {
                ans--;
            }
            else
            {
                ans -= 2;
            }
        }

        return ans;
    }
};