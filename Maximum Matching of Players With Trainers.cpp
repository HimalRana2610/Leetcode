#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int ans = 0;
        for (int i = 0, j = 0; i < players.size() && j < trainers.size(); j++)
        {
            if (players[i] <= trainers[j])
            {
                i++;
                ans++;
            }
        }

        return ans;
    }
};