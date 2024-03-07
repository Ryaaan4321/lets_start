#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
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
    ListNode *middleNode(ListNode *head)
    {
        int cnt = 0;
        ListNode *current = head;

        while (current != nullptr)
        {
            cnt++;
            current = current->next;
        }
        ListNode *slow = head;
        ListNode *fast = head;

        ListNode *ans;

        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            ans = slow;
            /* code */
        }

        return ans;
    }
};