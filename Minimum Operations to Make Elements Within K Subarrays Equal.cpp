#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void prune(auto &heap, unordered_map<int, int> &delayed)
    {
        while (!heap.empty())
        {
            if (delayed[heap.top()])
            {
                delayed[heap.top()]--;
                heap.pop();
            }
            else
            {
                break;
            }
        }
    }

    void balance(int &ls, int &rs, long long &suml, long long &sumr, auto &left, auto &right, unordered_map<int, int> &delayed)
    {
        if (ls > rs + 1)
        {
            int num = left.top();
            right.push(num);
            sumr += num;
            suml -= num;
            left.pop();
            rs++;
            ls--;
            prune(left, delayed);
        }
        else if (rs > ls)
        {
            int num = right.top();
            left.push(num);
            suml += num;
            sumr -= num;
            right.pop();
            ls++;
            rs--;
            prune(right, delayed);
        }
    }

    long long minOperations(vector<int> &nums, int x, int k)
    {
        int n = nums.size(), ls = 0, rs = 0;
        long long suml = 0, sumr = 0;
        vector<long long> ops(n);
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int>> right;
        unordered_map<int, int> delayed;

        for (int i = 0; i < n; i++)
        {
            if (left.empty() || nums[i] <= left.top())
            {
                left.push(nums[i]);
                ls++;
                suml += nums[i];
            }
            else
            {
                right.push(nums[i]);
                rs++;
                sumr += nums[i];
            }

            balance(ls, rs, suml, sumr, left, right, delayed);
            if (i >= x)
            {
                int num = nums[i - x];
                if (num <= left.top())
                {
                    ls--;
                    delayed[num]++;
                    suml -= num;

                    if (num == left.top())
                    {
                        prune(left, delayed);
                    }
                }
                else
                {
                    rs--;
                    delayed[num]++;
                    sumr -= num;

                    if (num == right.top())
                    {
                        prune(right, delayed);
                    }
                }
                balance(ls, rs, suml, sumr, left, right, delayed);
            }

            if (i >= x - 1)
            {
                long long mid = left.top();
                ops[i] = sumr - suml + mid * (ls - rs);
            }
        }

        vector<vector<long long>> dp(n, vector<long long>(k + 1, LLONG_MAX));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= k; j++)
        {
            if (j == 1)
            {
                dp[x - 1][j] = ops[x - 1];
            }
            else
            {
                dp[j * x - 1][j] = dp[(j - 1) * x - 1][j - 1] + ops[j * x - 1];
            }
        }
        for (int j = 1; j <= k; j++)
        {
            for (int i = j * x; i < n; i++)
            {
                dp[i][j] = min(dp[i - x][j - 1] + ops[i], dp[i - 1][j]);
            }
        }

        return dp[n - 1][k];
    }
};