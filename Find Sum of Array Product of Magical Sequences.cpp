#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(int m, int k, int index, int flag, vector<int> &nums, int n, vector<vector<vector<vector<int>>>> &dp, vector<vector<int>> &pascal)
    {
        int setbits = __builtin_popcount(flag);
        if (m < 0 || k < 0 || m + setbits < k)
        {
            return 0;
        }
        if (m == 0)
        {
            return (k == setbits) ? 1 : 0;
        }
        if (index >= n)
        {
            return 0;
        }
        if (dp[m][k][index][flag] != -1)
        {
            return dp[m][k][index][flag];
        }

        long long ans = 0, p = 1;
        for (int i = 0; i <= m; i++)
        {
            ans = (ans + (long long)pascal[m][i] * p % 1000000007 * dfs(m - i, k - ((flag + i) & 1), index + 1, (flag + i) >> 1, nums, n, dp, pascal)) % 1000000007;
            p = (p * nums[index]) % 1000000007;
        }

        return dp[m][k][index][flag] = ans;
    }

    int magicalSum(int m, int k, vector<int> &nums)
    {
        vector<vector<int>> pascal(31, vector<int>(31, 0));
        for (int i = 1; i <= 30; i++)
        {
            pascal[i][0] = pascal[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                pascal[i][j] = pascal[i][i - j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }

        int n = nums.size();
        vector<vector<vector<vector<int>>>> dp(m + 1, vector<vector<vector<int>>>(m + 1, vector<vector<int>>(n, vector<int>(31, -1))));

        return dfs(m, k, 0, 0, nums, n, dp, pascal);
    }
};