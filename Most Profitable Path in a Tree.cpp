#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool dfs(int node, int time, unordered_map<int, int>& path, vector<bool>& visited, vector<vector<int>>& graph)
    {
        path[node] = time;
        visited[node] = true;

        if(node == 0)
        {
            return true;
        }

        for(auto neighbour : graph[node])
        {
            if(!visited[neighbour])
            {
                if(dfs(neighbour, time + 1, path, visited, graph))
                {
                    return true;
                }
            }
        }

        path.erase(node);
        return false;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount)
    {
        int n = edges.size() + 1;
        vector<vector<int>> graph(n);

        for(int i = 0; i < n - 1; i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        unordered_map<int,int> path;
        vector<bool> visited(n, false);

        dfs(bob, 0, path, visited, graph);

        queue<vector<int>> q;
        q.push({0, 0, 0});
        visited.assign(n, false);

        int ans = INT_MIN;
        while(!q.empty())
        {
            int node = q.front()[0], time = q.front()[1], profit = q.front()[2];
            q.pop();
            visited[node] = true;

            if(path.find(node) == path.end())
            {
                profit += amount[node];
            }
            else
            {
                if(time < path[node])
                {
                    profit += amount[node];
                }
                else if(time == path[node])
                {
                    profit += amount[node] / 2;
                }
            }

            if(graph[node].size() == 1 && node != 0)
            {
                ans = max(ans, profit);
            }

            for(auto neighbour : graph[node])
            {
                if(!visited[neighbour])
                {
                    q.push({neighbour, time + 1, profit});
                }
            }
        }

        return ans;
    }
};