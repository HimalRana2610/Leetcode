#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long maxMatrixSum(vector<vector<int>>& matrix)
    {
        int n = matrix.size(), m = numeric_limits<int>::max(), c = 0;
        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] < 0)
                {
                    c++;
                }
                m = min(m, abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
            }
        }

        if(c % 2 == 0)
        {
            return sum;
        }
        return sum - 2 * m;
    }
};