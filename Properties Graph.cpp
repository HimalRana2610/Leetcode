#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool intersect(vector<int> a, vector<int> b, int k)
    {
        unordered_map<int, int> freq;
        int ans = 0;

        for(int x : a)
        {
            freq[x]++;
        }
        for(int x : b)
        {
            if(freq[x] > 0)
            {
                ans++;
                freq[x] = 0;
                if(ans >= k)
                {
                    return true;
                }
            }
        }

        return ans >= k;
    }

    void dfs(int node, vector<vector<int>> graph, vector<bool>& visited)
    {
        visited[node] = true;
        for(int neighbour : graph[node])
        {
            if(!visited[neighbour])
            {
                dfs(neighbour, graph, visited);
            }
        }
    }

    int numberOfComponents(vector<vector<int>>& properties, int k)
    {
        int n = properties.size(), m = properties[0].size();
        vector<vector<int>> graph(n);

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(intersect(properties[i], properties[j], k))
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                dfs(i, graph, visited);
                ans++;
            }
        }

        return ans;
    }
};