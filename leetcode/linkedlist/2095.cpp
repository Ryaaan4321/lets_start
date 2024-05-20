#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x){
        val=x;
        next=nullptr;
    }
};
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==nullptr){
            return nullptr;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next->next!=nullptr && fast->next->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=slow->next->next;
        return head;

    }
};