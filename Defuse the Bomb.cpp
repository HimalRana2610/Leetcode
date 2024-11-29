#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> decrypt(vector<int>& code, int k)
    {
        int n = code.size();
        if(k == 0)
        {
            return vector<int>(n, 0);
        }

        vector<int> ans(n, 0);
        if(k > 0)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 1; j <= k; j++)
                {
                    ans[i] += code[(i + j) % n];
                }
            }
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = k; j < 0; j++)
                {
                    ans[i] += code[(i + j + n) % n];
                }
            }
        }

        return ans;
    }
};