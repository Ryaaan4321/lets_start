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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* tmp=head;
        while(tmp!=nullptr){
            while(!st.empty() && st.top()->val < tmp->val)
            {
                st.pop();
            }
            st.push(tmp);
            tmp=tmp->next;
        }
        ListNode* nxt=nullptr;
        while(!st.empty()){
            tmp=st.top();
            st.pop();
            tmp->next=nxt;
            nxt=tmp;
        }
        return tmp;
    }
};