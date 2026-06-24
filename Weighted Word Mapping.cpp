#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string mapWordWeights(vector<string> &words, vector<int> &weights)
    {
        string ans;
        for (int i = 0; i < words.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < words[i].length(); j++)
            {
                sum += weights[words[i][j] - 'a'];
            }
            ans.push_back('z' - (sum % 26));
        }

        return ans;
    }
};