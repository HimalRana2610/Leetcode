#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int countSymmetricIntegers(int low, int high)
    {
        int ans = 0;
        for(int i = low; i <= high; i++)
        {
            string str = to_string(i);
            int l = str.length();

            if(l % 2 == 0)
            {
                int sum = 0;
                for(int j = 0; j < l / 2; j++)
                {
                    sum += (str[j] - '0');
                }
                for(int j = l / 2; j < l; j++)
                {
                    sum -= (str[j] - '0');
                }

                if(sum == 0)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};