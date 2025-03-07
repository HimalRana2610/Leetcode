#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool is_prime(int n)
    {
        if(n <= 1)
        {
            return false;
        }
        else if(n == 2)
        {
            return true;
        }
        else if(n % 2 == 0)
        {
            return false;
        }

        for(int i = 3; i <= sqrt(n); i += 2)
        {
            if(n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    vector<int> closestPrimes(int left, int right)
    {
        vector<int> primes;
        for(int i = left; i <= right; i++)
        {
            if(is_prime(i))
            {
                primes.push_back(i);
            }
        }

        if(primes.size() < 2)
        {
            return {-1, -1};
        }

        vector<int> ans(2);
        ans[0] = primes[0];
        ans[1] = primes[1];
        int diff = primes[1] - primes[0];

        for(int i = 2; i < primes.size(); i++)
        {
            if(primes[i] - primes[i - 1] < diff)
            {
                ans[0] = primes[i - 1];
                ans[1] = primes[i];
                diff = primes[i] - primes[i - 1];
            }
        }

        return ans;
    }
};