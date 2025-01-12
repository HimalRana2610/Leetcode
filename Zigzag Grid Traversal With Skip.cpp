#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid)
    {
        vector<int> ans;
        bool flag = true;

        for(int i = 0; i < grid.size(); i++)
        {
            if(i % 2 == 0)
            {
                for(int j = 0; j < grid[0].size(); j++)
                {
                    if(flag)
                    {
                        ans.push_back(grid[i][j]);
                    }
                    flag = !flag;
                }
            }
            else
            {
                for(int j = grid[0].size() - 1; j >= 0; j--)
                {
                    if(flag)
                    {
                        ans.push_back(grid[i][j]);
                    }
                    flag = !flag;
                }
            }
        }

        return ans;
    }
};