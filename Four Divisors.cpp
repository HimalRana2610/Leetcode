#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumFourDivisors(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int cnt = 0, sum = 0;
            for (int j = 1; j * j <= nums[i]; j++)
            {
                if (nums[i] % j == 0)
                {
                    cnt++;
                    sum += j;

                    if (j != nums[i] / j)
                    {
                        cnt++;
                        sum += nums[i] / j;
                    }
                }

                if (cnt > 4)
                {
                    break;
                }
            }

            if (cnt == 4)
            {
                ans += sum;
            }
        }

        return ans;
    }
};