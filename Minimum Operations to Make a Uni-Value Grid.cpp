#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int minOperations(vector<vector<int>>& grid, int x)
    {
        vector<int> arr;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                arr.push_back(grid[i][j]);
            }
        }

        sort(arr.begin(), arr.end());

        int median = arr[arr.size() / 2], ans = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            if(abs(arr[i] - arr[0]) % x != 0)
            {
                return -1;
            }
            ans += abs(arr[i] - median) / x;
        }

        return ans;
    }
};