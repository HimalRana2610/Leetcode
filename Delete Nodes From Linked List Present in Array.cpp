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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        ListNode *nhead = new ListNode(0, head);
        unordered_set<int> s(nums.begin(), nums.end());
        ListNode *ptr = nhead;

        while (true)
        {
            if (!(ptr->next))
            {
                break;
            }
            if (s.find(ptr->next->val) != s.end())
            {
                ptr->next = ptr->next->next;
            }
            else
            {
                ptr = ptr->next;
            }
        }

        return nhead->next;
    }
};