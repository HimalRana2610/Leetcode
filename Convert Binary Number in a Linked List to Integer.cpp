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
    int getDecimalValue(ListNode *head)
    {
        vector<int> num;
        while (head)
        {
            num.push_back(head->val);
            head = head->next;
        }

        int n = num.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (num[i] == 1)
            {
                ans += (1 << (n - i - 1));
            }
        }

        return ans;
    }
};