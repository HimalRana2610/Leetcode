#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 1)
        {
            return {{1}};
        }

        vector<vector<int>> ans = {{1}, {1, 1}};
        for (int i = 2; i < numRows; i++)
        {
            vector<int> current;
            current.push_back(ans[i - 1][0]);

            for (int j = 1; j < ans[i - 1].size(); j++)
            {
                current.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            }

            current.push_back(ans[i - 1][ans[i - 1].size() - 1]);
            ans.push_back(current);
        }

        return ans;
    }
};