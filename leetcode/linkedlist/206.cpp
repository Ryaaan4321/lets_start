#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class ListNode{
    public:
    ListNode* next;
    int val;
    ListNode(int x){
        val=x;
        next=nullptr;
    }
};
class Solution{
    public:
     ListNode* reverseList(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        stack<ListNode*>st;
        while(head!=nullptr){
            st.push(head);
            head=head->next;
        }
        ListNode* tmp=st.top();
        ListNode* newhead=tmp;
        st.pop();
        while(!st.empty()){
            tmp->next=st.top();
            st.pop();
            tmp=tmp->next;
        }
        tmp->next=nullptr;
        return newhead;
    }
};
