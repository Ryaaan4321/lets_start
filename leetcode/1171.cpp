#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        vector<int> a;
        ListNode *current = head;
        while (current)
        {
            a.push_back(current->val);
            current = current->next;
        }

        for (int i = 1; i < a.size(); i++)
        {
            if (a[i - 1] + a[i] == 0)
            {
                a.erase(a.begin() + i - 1, a.begin() + i + 1);
            }
            i++;
        }
        ListNode *temp = new ListNode(0);
        ListNode *cur = temp;
        for (int val : a)
        {
            cur->next = new ListNode(val);
            cur = cur->next;
        }
        ListNode *head = temp->next;
        delete temp;
        return head;
    }
};