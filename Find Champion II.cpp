#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int findChampion(int n, vector<vector<int>>& edges)
    {
        set<int> s;
        for(int i = 0; i < n; i++)
        {
            s.insert(i);
        }

        for(int i = 0; i < edges.size(); i++)
        {
            if(s.find(edges[i][1]) != s.end())
            {
                s.erase(edges[i][1]);
            }
        }

        if(s.size() == 1)
        {
            return *s.begin();
        }

        return -1;
    }
};