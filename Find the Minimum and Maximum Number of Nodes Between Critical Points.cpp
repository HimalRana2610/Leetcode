#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        int mi = INT_MAX, ma = INT_MIN, prev = -1, idx = -1, first = -1;
        ListNode *current = head;

        for (int i = 0; current; i++, current = current->next)
        {
            if (prev != -1 && current->next)
            {
                if ((current->val > prev && current->val > current->next->val) || (current->val < prev && current->val < current->next->val))
                {
                    if (idx == -1)
                    {
                        first = i;
                    }
                    else
                    {
                        mi = min(mi, i - idx);
                        ma = i - first;
                    }
                    idx = i;
                }
            }
            prev = current->val;
        }

        if (mi == INT_MAX)
        {
            return {-1, -1};
        }

        return {mi, ma};
    }
};