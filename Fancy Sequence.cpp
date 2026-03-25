#include <bits/stdc++.h>
using namespace std;

class Fancy
{
    vector<long long> arr;
    long long mul = 1, add = 0;

    long long modInverse(long long x)
    {
        long long ans = 1, p = 1000000005;
        while (p)
        {
            if (p & 1)
            {
                ans = ans * x % 1000000007;
            }

            x = x * x % 1000000007;
            p >>= 1;
        }

        return ans;
    }

public:
    Fancy() {}

    void append(int val)
    {
        long long inv = modInverse(mul);
        long long v = ((val - add + 1000000007) % 1000000007) * inv % 1000000007;
        arr.push_back(v);
    }

    void addAll(int inc)
    {
        add = (add + inc) % 1000000007;
    }

    void multAll(int m)
    {
        mul = (mul * m) % 1000000007;
        add = (add * m) % 1000000007;
    }

    int getIndex(int idx)
    {
        if (idx >= arr.size())
        {
            return -1;
        }

        return (arr[idx] * mul % 1000000007 + add) % 1000000007;
    }
};