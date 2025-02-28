#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int lenLongestFibSubseq(vector<int>& arr)
    {
        unordered_set<int> s(arr.begin(), arr.end());
        int ans = 0;

        for(int i = 0; i < arr.size(); i++)
        {
            for(int j = i + 1; j < arr.size(); j++)
            {
                int prev = arr[j], current = arr[i] + arr[j], len = 2;
                while(s.find(current) != s.end())
                {
                    int temp = current;
                    current += prev;
                    prev = temp;
                    ans = max(ans, ++len);
                }
            }
        }

        return ans;
    }
};