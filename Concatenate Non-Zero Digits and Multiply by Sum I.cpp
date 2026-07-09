#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long sumAndMultiply(int n)
    {
        int sum = 0;
        string x;

        while (n > 0)
        {
            int current = n % 10;
            n /= 10;
            sum += current;

            if (current != 0)
            {
                x = to_string(current) + x;
            }
        }

        if (x.empty())
        {
            return 0;
        }

        return 1LL * sum * stoi(x);
    }
};