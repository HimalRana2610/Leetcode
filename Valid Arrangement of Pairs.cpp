#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs)
    {
        unordered_map<int, vector<int>> list;
        unordered_map<int, int> degree;

        for(auto &pair : pairs)
        {
            list[pair[0]].push_back(pair[1]);
            degree[pair[0]]++;
            degree[pair[1]]--;
        }

        int start = pairs[0][0];
        for(auto &pair : degree)
        {
            if(pair.second == 1)
            {
                start = pair.first;
                break;
            }
        }

        vector<int> path;
        stack<int> st;
        st.push(start);

        while(!st.empty())
        {
            auto &n = list[st.top()];
            if(n.empty())
            {
                path.push_back(st.top());
                st.pop();
            }
            else
            {
                st.push(n.back());
                n.pop_back();
            }
        }

        vector<vector<int>> ans;
        ans.reserve(path.size());

        for(int i = path.size() - 1; i > 0; i--)
        {
            ans.push_back({path[i], path[i - 1]});
        }

        return ans;
    }
};