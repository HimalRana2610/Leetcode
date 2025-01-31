#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat)
    {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> position;
        vector<int> row(m, n), col(n, m);

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                position[mat[i][j]] = {i, j};
            }
        }

        for(int i = 0; i < arr.size(); i++)
        {
            int r = position[arr[i]].first, c = position[arr[i]].second;
            if(--row[r] == 0 || --col[c] == 0)
            {
                return i;
            }
        }

        return -1;
    }
};