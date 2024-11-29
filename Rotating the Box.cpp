#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box)
    {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));

        for(int i = 0; i < m; i++)
        {
            int t = n - 1;
            for(int j = n - 1; j >= 0; j--)
            {
                if(box[i][j] == '#')
                {
                    ans[t][m - i - 1] = '#';
                    t--;
                }
                else if(box[i][j] == '*')
                {
                    ans[j][m - i - 1] = '*';
                    t = j - 1;
                }
            }
        }

        return ans;
    }
};