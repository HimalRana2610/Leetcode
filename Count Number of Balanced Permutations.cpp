#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int countBalancedPermutations(string num)
    {
        int sum = 0, n = num.length();
        unordered_map<int, int> freq;

        for(int i = 0; i < n; i++)
        {
            freq[num[i] - '0']++;
            sum += num[i] - '0';
        }

        if(sum % 2 != 0)
        {
            return 0;
        }

        int target = sum / 2, maxOdd = (n + 1) / 2;
        vector<vector<long long>> perm(maxOdd + 1, vector<long long>(maxOdd + 1));

        for(int i = 0; i <= maxOdd; i++)
        {
            perm[i][i] = perm[i][0] = 1;
            for(int j = 1; j < i; j++)
            {
                perm[i][j] = (perm[i - 1][j] + perm[i - 1][j - 1]) % 1000000007;
            }
        }

        vector<vector<long long>> dp(target + 1, vector<long long>(maxOdd + 1));
        dp[0][0] = 1;

        int psum = 0, total = 0;
        for(int i = 0; i <= 9; i++)
        {
            psum += freq[i];
            total += i * freq[i];

            for(int oddCnt = min(psum, maxOdd); oddCnt >= max(0, psum - (n - maxOdd)); oddCnt--)
            {
                int evenCnt = psum - oddCnt;
                for(int curr = min(total, target); curr >= max(0, total - target); curr--)
                {
                    long long res = 0;
                    for(int j = max(0, freq[i] - evenCnt); j <= min(freq[i], oddCnt) && i * j <= curr; j++)
                    {
                        long long ways = perm[oddCnt][j] * perm[evenCnt][freq[i] - j] % 1000000007;
                        res = (res + ways * dp[curr - i * j][oddCnt - j] % 1000000007) % 1000000007;
                    }
                    dp[curr][oddCnt] = res % 1000000007;
                }
            }
        }

        return dp[target][maxOdd];
    }
};