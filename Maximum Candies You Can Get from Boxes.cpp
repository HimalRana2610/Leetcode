#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxCandies(vector<int> &status, vector<int> &candies, vector<vector<int>> &keys, vector<vector<int>> &containedBoxes, vector<int> &initialBoxes)
    {
        bool found = true;
        int ans = 0;

        while (!initialBoxes.empty() && found)
        {
            found = false;
            vector<int> nextBoxes;

            for (int i = 0; i < initialBoxes.size(); i++)
            {
                if (status[initialBoxes[i]] == 1)
                {
                    found = true;
                    nextBoxes.insert(end(nextBoxes), begin(containedBoxes[initialBoxes[i]]), end(containedBoxes[initialBoxes[i]]));

                    for (int j = 0; j < keys[initialBoxes[i]].size(); j++)
                    {
                        status[keys[initialBoxes[i]][j]] = 1;
                    }
                    ans += candies[initialBoxes[i]];
                }
                else
                {
                    nextBoxes.push_back(initialBoxes[i]);
                }
            }
            swap(initialBoxes, nextBoxes);
        }

        return ans;
    }
};