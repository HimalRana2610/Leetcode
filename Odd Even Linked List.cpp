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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *odd = head;
        ListNode *even = head->next;

        ListNode *current = even;
        while (current && current->next)
        {
            odd->next = current->next;
            odd = odd->next;
            current->next = current->next->next;
            current = current->next;
        }

        odd->next = even;
        return head;
    }
};