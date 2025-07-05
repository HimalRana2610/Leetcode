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
    int pairSum(ListNode *head)
    {
        vector<int> arr;
        while (head)
        {
            arr.push_back(head->val);
            head = head->next;
        }

        int n = arr.size(), ans = 0;
        for (int i = 0; i < n / 2; i++)
        {
            ans = max(ans, arr[i] + arr[n - i - 1]);
        }

        return ans;
    }
};