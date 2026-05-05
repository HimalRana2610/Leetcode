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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k == 0)
        {
            return head;
        }

        ListNode *ptr = head;
        int cnt = 1;

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            cnt++;
        }

        ptr->next = head;
        k = k % cnt;
        k = cnt - k;

        while (k--)
        {
            ptr = ptr->next;
        }

        head = ptr->next;
        ptr->next = NULL;

        return head;
    }
};