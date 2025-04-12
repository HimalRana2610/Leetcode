#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long countGoodIntegers(int n, int k)
    {
        unordered_set<string> s;
        int start = pow(10, (n - 1) / 2), offset = n & 1;

        for(int i = start; i < start * 10; i++)
        {
            string str = to_string(i);
            str += string(str.rbegin() + offset, str.rend());

            long long p = stoll(str);
            if(p % k == 0)
            {
                sort(str.begin(), str.end());
                s.insert(str);
            }
        }

        vector<long long> fact(n + 1, 1);
        for(int i = 1; i <= n; i++)
        {
            fact[i] = fact[i - 1] * i;
        }

        long long ans = 0;
        for(auto &str : s)
        {
            vector<int> cnt(10);
            for(int i = 0; i < str.length(); i++)
            {
                cnt[str[i] - '0']++;
            }

            long long current = (n - cnt[0]) * fact[n - 1];
            for(int i = 0; i < 10; i++)
            {
                current /= fact[cnt[i]];
            }

            ans += current;
        }

        return ans;
    }
};