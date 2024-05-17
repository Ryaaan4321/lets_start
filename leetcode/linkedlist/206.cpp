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
        stack<ListNode*>st;
        while(head!=nullptr){
            st.push(head);
            head=head->next;
        }
        ListNode* tmp=st.top();
        st.pop();
        while(!st.empty()){
            tmp->next=st.top();
            st.pop();
            tmp=tmp->next;
        }
        return tmp;
        
    }
};
