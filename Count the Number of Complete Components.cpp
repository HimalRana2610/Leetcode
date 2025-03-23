#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited, vector<int>& component)
    {
        visited[node] = true;
        component.push_back(node);

        for(int neighbour : graph[node])
        {
            if(!visited[neighbour])
            {
                dfs(graph, neighbour, visited, component);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> graph(n);
        for(int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> visited(n, false);
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                vector<int> component;
                dfs(graph, i, visited, component);

                ans++;
                for(int j = 0; j < component.size(); j++)
                {
                    if(graph[component[j]].size() != component.size() - 1)
                    {
                        ans--;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};