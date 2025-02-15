#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries)
    {
        unordered_map<int, int> color, ball;
        vector<int> ans;

        int distinct = 0;
        for(int i = 0; i < queries.size(); i++)
        {
            if(ball.count(queries[i][0]))
            {
                if(--color[ball[queries[i][0]]] == 0)
                {
                    distinct--;
                }
            }

            ball[queries[i][0]] = queries[i][1];
            if(++color[queries[i][1]] == 1)
            {
                distinct++;
            }

            ans.push_back(distinct);
        }

        return ans;
    }
};