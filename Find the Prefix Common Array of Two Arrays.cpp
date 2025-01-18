#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B)
    {
        int n = A.size();
        vector<int> ans(n, 0);
        set<int> s;
        for(int i = 0; i < n; i++)
        {
            s.insert(A[i]);
            for(int j = 0; j <= i; j++)
            {
                if(s.find(B[j]) != s.end())
                {
                    ans[i]++;
                }
            }
        }

        return ans;
    }
};