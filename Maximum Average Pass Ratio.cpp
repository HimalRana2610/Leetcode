#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents)
    {
        int n = classes.size();
        auto improvement = [](const vector<int>& c)
        {
            double pass = c[0], total = c[1];
            return (pass + 1) / (total + 1) - pass / total;
        };

        priority_queue<pair<double, int>> pq;
        for(int i = 0; i < n; i++)
        {
            pq.push({improvement(classes[i]), i});
        }

        while(extraStudents--)
        {
            pair<double, int> p = pq.top();
            pq.pop();

            double imp = p.first;
            int idx = p.second;
            
            classes[idx][0]++;
            classes[idx][1]++;
            
            pq.push({improvement(classes[idx]), idx});
        }

        double sum = 0.0;
        for(int i = 0; i < n; i++)
        {
            sum += (double)classes[i][0] / classes[i][1];
        }

        return sum / n;
    }
};