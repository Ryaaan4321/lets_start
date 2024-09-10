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
    bool hasCycle(ListNode *head) {
        ListNode* s=head;
        ListNode* f=head->next;
        if(head==NULL && head->next==NULL){
            return 0;
        }
        while(s!=f){
            if(f->next==nullptr && f->next->next==nullptr){
                return 0;
            }
            s=s->next;
            f=f->next->next;
        }
        return 1;
    }
};