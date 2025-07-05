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
    ListNode *deleteMiddle(ListNode *head)
    {
        if (!head->next)
        {
            return nullptr;
        }

        int n = 1;
        ListNode *current = head;

        while (current->next)
        {
            n++;
            current = current->next;
        }

        n /= 2;
        current = head;

        while (--n)
        {
            current = current->next;
        }

        current->next = current->next->next;
        return head;
    }
};