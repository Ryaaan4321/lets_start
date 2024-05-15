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
    ListNode* arrtoll(vector<int>a){
        int n=a.size();
        ListNode* root=new ListNode(a[0]);
        ListNode* pointer=root;
        for(int i=1;i<a.size();i++){
            ListNode* tmp=new ListNode(a[i]);
            pointer->next=tmp;
            pointer->next=pointer;
        }
        return root;
    }
    void print(ListNode* root){
        while(!root){
            cout<<root->val<< " ";
            root=root->next;
        }
    }
    // ListNode* insertAthead(ListNode* head,int val){
    //        return new ListNode(val,head);
    // }
    ListNode* insertAtTail(ListNode* head,int val){
        if(head==NULL){
            return new ListNode(val);
        }
        ListNode* tmp=head;
        while (tmp->next!=NULL)
        {
            tmp=tmp->next;

        }
        ListNode* nNode=new ListNode(val);
        tmp->next=nNode;
        return head;
    }


};