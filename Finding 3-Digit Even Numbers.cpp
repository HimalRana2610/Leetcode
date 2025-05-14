#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> findEvenNumbers(vector<int>& digits)
    {
        int n = digits.size();
        unordered_set<int> s;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    if(i == j || i == k || j == k)
                    {
                        continue;
                    }

                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if(num > 99 && num % 2 == 0)
                    {
                        s.insert(num);
                    }
                }
            }
        }

        vector<int> ans(s.begin(), s.end());
        sort(ans.begin(), ans.end());

        return ans;
    }
};