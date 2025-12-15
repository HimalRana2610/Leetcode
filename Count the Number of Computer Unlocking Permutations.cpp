#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPermutations(vector<int> &complexity)
    {
        int n = complexity.size(), m = *min_element(complexity.begin() + 1, complexity.end());
        if (m <= complexity[0])
        {
            return 0;
        }

        int ans = 1;
        for (int i = 2; i < n; i++)
        {
            ans = (1LL * ans * i) % 1000000007;
        }

        return ans;
    }
};