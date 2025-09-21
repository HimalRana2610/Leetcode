#include <bits/stdc++.h>
using namespace std;

class TaskManager
{
    unordered_map<int, pair<int, int>> taskInfo;
    priority_queue<pair<int, int>> pq;

public:
    TaskManager(vector<vector<int>> &tasks)
    {
        for (auto &t : tasks)
        {
            int userId = t[0], taskId = t[1], priority = t[2];
            taskInfo[taskId] = {userId, priority};
            pq.emplace(priority, taskId);
        }
    }

    void add(int userId, int taskId, int priority)
    {
        taskInfo[taskId] = {userId, priority};
        pq.emplace(priority, taskId);
    }

    void edit(int taskId, int newPriority)
    {
        pair<int, int> info = taskInfo[taskId];
        int userId = info.first;
        taskInfo[taskId] = {userId, newPriority};
        pq.emplace(newPriority, taskId);
    }

    void rmv(int taskId)
    {
        taskInfo.erase(taskId);
    }

    int execTop()
    {
        while (!pq.empty())
        {
            pair<int, int> top = pq.top();
            pq.pop();
            int priority = top.first, taskId = top.second;
            if (taskInfo.count(taskId) && taskInfo[taskId].second == priority)
            {
                int userId = taskInfo[taskId].first;
                taskInfo.erase(taskId);
                return userId;
            }
        }

        return -1;
    }
};