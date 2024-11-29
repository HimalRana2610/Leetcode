#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int bfs(int n, map<int, vector<int>> &graph)
    {
        vector<int> distance(n, -1);
        queue<int> q;

        distance[0] = 0;
        q.push(0);

        while(!q.empty())
        {
            int c = q.front();
            q.pop();

            for(int i : graph[c])
            {
                if(distance[i] == -1)
                {
                    distance[i] = distance[c] + 1;
                    q.push(i);
                }
            }
        }

        return distance[n - 1];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries)
    {
        map<int, vector<int>> graph;
        for(int i = 0; i < n - 1; i++)
        {
            graph[i].push_back(i + 1);
        }

        vector<int> ans;
        for(int i = 0; i < queries.size(); i++)
        {
            graph[queries[i][0]].push_back(queries[i][1]);
            ans.push_back(bfs(n, graph));
        }
        return ans;
    }
};