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
        if(n <= 3)
        {
            return true;
        }
        if(n % 2 == 0 || n % 3 == 0)
        {
            return false;
        }

        for(int i = 5; i * i <= n; i += 6)
        {
            if(n % i == 0 || n % (i + 2) == 0)
            {
                return false;
            }
        }
        return true;
    }

    bool primeSubOperation(vector<int>& nums)
    {
        int prev = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= prev)
            {
                return false;
            }

            bool found = false;
            for(int j = nums[i] - 1; j > 1; j--)
            {
                if(is_prime(j))
                {
                    if(prev >= nums[i] - j)
                    {
                        continue;
                    }

                    prev = nums[i] - j;
                    found = true;
                    break;
                }
            }

            if(!found)
            {
                if(nums[i] > prev)
                {
                    prev = nums[i];
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};