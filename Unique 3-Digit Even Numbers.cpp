#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int totalNumbers(vector<int>& digits)
    {
        unordered_set<int> numbers;
        int n = digits.size();

        for(int i = 0; i < n; i++)
        {
            if(digits[i] == 0)
            {
                continue;
            }

            for(int j = 0; j < n; j++)
            {
                if(j == i)
                {
                    continue;
                }

                for(int k = 0; k < n; k++)
                {
                    if(k == i || k == j || digits[k] % 2 != 0)
                    {
                        continue;
                    }

                    numbers.insert(digits[i] * 100 + digits[j] * 10 + digits[k]);
                }
            }
        }

        return numbers.size();
    }
};