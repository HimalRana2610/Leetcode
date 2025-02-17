#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int backtrack(string &tiles, vector<bool>& used)
    {
        int ans = 0;
        for(int i = 0; i < tiles.length(); i++)
        {
            if(used[i] || (i > 0 && tiles[i] == tiles[i - 1] && !used[i - 1]))
            {
                continue;
            }

            used[i] = true;
            ans += 1 + backtrack(tiles, used);
            used[i] = false;
        }

        return ans;
    }

    int numTilePossibilities(string tiles)
    {
        sort(tiles.begin(), tiles.end());
        vector<bool> used(tiles.length(), false);

        return backtrack(tiles, used);
    }
};