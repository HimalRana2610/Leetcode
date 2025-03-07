#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid)
    {
        int n = grid.size();
        unordered_set<int> s;
        unordered_map<int, int> freq;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                s.insert(grid[i][j]);
                freq[grid[i][j]]++;
            }
        }

        int a, b;
        for(int i = 1; i <= n * n; i++)
        {
            if(s.find(i) == s.end())
            {
                b = i;
            }
            else if(freq[i] == 2)
            {
                a = i;
            }
        }

        return {a, b};
    }
};