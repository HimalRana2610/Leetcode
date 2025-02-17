#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool backtrack(vector<int>& ans, vector<bool>& used, int n, int index)
    {
        while(index < ans.size() && ans[index] != 0)
        {
            index++;
        }

        if(index == ans.size())
        {
            return true;
        }

        for(int i = n; i > 0; i--)
        {
            if(used[i])
            {
                continue;
            }
            if(i == 1)
            {
                ans[index] = 1;
                used[1] = true;

                if(backtrack(ans, used, n, index + 1))
                {
                    return true;
                }

                ans[index] = 0;
                used[1] =false;
            }
            else if(index + i < ans.size() && ans[index + i] == 0)
            {
                ans[index] = ans[index + i] = i;
                used[i] = true;

                if(backtrack(ans, used, n, index + 1))
                {
                    return true;
                }

                ans[index] = ans[index + i] = 0;
                used[i] = false;
            }
        }

        return false;
    }

    vector<int> constructDistancedSequence(int n)
    {
        vector<int> ans(2 * n - 1, 0);
        vector<bool> used(n + 1, false);

        backtrack(ans, used, n, 0);
        return ans;
    }
};