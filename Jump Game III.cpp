#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int idx, vector<int> &arr, vector<bool> &visited)
    {
        int n = arr.size();
        if (arr[idx] == 0)
        {
            return true;
        }

        if (idx - arr[idx] >= 0 && idx - arr[idx] < n && !visited[idx - arr[idx]])
        {
            visited[idx - arr[idx]] = true;
            if (dfs(idx - arr[idx], arr, visited))
            {
                return true;
            }
            visited[idx - arr[idx]] = false;
        }
        if (idx + arr[idx] >= 0 && idx + arr[idx] < n && !visited[idx + arr[idx]])
        {
            visited[idx + arr[idx]] = true;
            if (dfs(idx + arr[idx], arr, visited))
            {
                return true;
            }
            visited[idx + arr[idx]] = false;
        }

        return false;
    }

    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size();
        vector<bool> visited(n, false);
        visited[start] = true;

        return dfs(start, arr, visited);
    }
};