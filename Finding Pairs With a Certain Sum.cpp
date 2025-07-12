#include <bits/stdc++.h>
using namespace std;

class FindSumPairs
{
    vector<int> arr1, arr2;
    unordered_map<int, int> freq;

public:
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        arr1 = nums1;
        arr2 = nums2;

        for (int i = 0; i < arr2.size(); i++)
        {
            freq[arr2[i]]++;
        }
    }

    void add(int index, int val)
    {
        freq[arr2[index]]--;
        arr2[index] += val;
        freq[arr2[index]]++;
    }

    int count(int tot)
    {
        int ans = 0;
        for (int i = 0; i < arr1.size(); i++)
        {
            ans += freq[tot - arr1[i]];
        }

        return ans;
    }
};