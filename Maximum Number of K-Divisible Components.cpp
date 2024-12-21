#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k)
    {
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        int ans = 0;
        function<long long(int, int)> dfs = [&](int node, int parent) -> long long
        {
            long long sum = values[node];
            for(int i : graph[node])
            {
                if(i != parent)
                {
                    sum += dfs(i, node);
                }
            }

            if(sum % k == 0)
            {
                ans++;
                return 0;
            }

            return sum;
        };

        dfs(0, -1);
        return ans;
    }
};