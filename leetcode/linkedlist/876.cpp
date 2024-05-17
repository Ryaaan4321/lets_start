#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class ListNode
{
public:
    ListNode* next;
    int val;
    ListNode(int x){
        val=x;
        next=NULL;
    }
};
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* s = head;
        ListNode* f = head;
        ListNode* a;
        while (f!=nullptr && f->next!=nullptr) {
            s = s->next;
            f = f->next->next;
            a = s;
        }
        return a;
    }
};