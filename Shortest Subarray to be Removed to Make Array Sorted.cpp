#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int findLengthOfShortestSubarray(vector<int>& arr)
    {
        int d = arr.size() - 1;
        for(int i = d; i >= 1; i--)
        {
            if(arr[i] >= arr[i - 1] && d > 0)
            {
                d--;
            }
            else
            {
                break;
            }
        }

        int ans = d;
        for(int i = 0; i < d && (i == 0 || arr[i - 1] <= arr[i]); i++)
        {
            while(d < arr.size() && arr[i] > arr[d])
            {
                d++;
            }

            ans = min(ans, d - i - 1);
        }

        return ans;
    }
};