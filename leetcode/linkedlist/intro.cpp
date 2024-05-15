#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int x){
        val=x;
        next=NULL;
    }
};
class Solution{
    public:
    ListNode* convert(vector<int>ar){
        ListNode* head=new ListNode(ar[0]);
        ListNode* nxt=head;
        for(int i=1;i<ar.size();i++){
            ListNode* tmp=new ListNode(ar[i]);
            nxt->next=tmp;
            nxt=nxt->next;
        }
        return head;
    }

};