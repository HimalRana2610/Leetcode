#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        double m = 0;
        int ans = 0;

        for (int i = 0; i < dimensions.size(); i++)
        {
            if (sqrt((dimensions[i][0] * dimensions[i][0]) + (dimensions[i][1] * dimensions[i][1])) > m)
            {
                m = sqrt((dimensions[i][0] * dimensions[i][0]) + (dimensions[i][1] * dimensions[i][1]));
                ans = dimensions[i][0] * dimensions[i][1];
            }
            else if (sqrt((dimensions[i][0] * dimensions[i][0]) + (dimensions[i][1] * dimensions[i][1])) == m)
            {
                ans = max(ans, dimensions[i][0] * dimensions[i][1]);
            }
        }

        return ans;
    }
};