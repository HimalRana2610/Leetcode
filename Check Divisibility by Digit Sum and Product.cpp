#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkDivisibility(int n)
    {
        int num = n, sum = 0, prod = 1;
        while (num > 0)
        {
            sum += num % 10;
            prod *= num % 10;
            num /= 10;
        }

        return (n % (sum + prod)) == 0;
    }
};