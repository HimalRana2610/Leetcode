#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        unordered_map<int, int> freq;
        int ans = 0;

        for (int i = 0, j = 0; i < fruits.size(); i++)
        {
            freq[fruits[i]]++;
            while (freq.size() > 2)
            {
                freq[fruits[j]]--;
                if (freq[fruits[j]] == 0)
                {
                    freq.erase(fruits[j]);
                }
                j++;
            }
            ans = max(ans, i - j + 1);
        }

        return ans;
    }
};