#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestNumber(int n)
    {
        vector<int> arr = {1, 3, 7, 15, 31, 63, 127, 255, 511, 1023};
        return *lower_bound(arr.begin(), arr.end(), n);
    }
};