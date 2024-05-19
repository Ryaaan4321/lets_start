#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    int pairSum(ListNode* head) {
        int a[100000];
        int idx = 0;
        while (head != nullptr) {
            a[idx++] = head->val;
            head = head->next;
        }
        int maxSum = 0;
        for (int i = 0; i < idx / 2; i++) {
            int twinSum = a[i] + a[idx - 1 - i];
            maxSum = std::max(maxSum, twinSum);
        }
        return maxSum;
    }
};