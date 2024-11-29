#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        map<string, int> freq;

        for(int i = 0; i < m; i++)
        {
            string p;
            if(matrix[i][0] == 0)
            {
                for(int j = 0; j < n; j++)
                {
                    p += to_string(matrix[i][j]);
                }
            }
            else
            {
                for(int j = 0; j < n; j++)
                {
                    p += to_string(matrix[i][j] ^ 1);
                }
            }
            freq[p]++;
        }

        int ans = 0;
        for(auto &f : freq)
        {
            ans = max(ans, f.second);
        }
        return ans;
    }
};