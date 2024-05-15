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
    ListNode* removehead(ListNode* root){
        if(root==NULL)return root;
        root=root->next;
        return root;
    }
    ListNode* removeTail(ListNode* root){
        if(root==NULL){
            return NULL;
        }
        if(root->next==NULL){
            return NULL;
        }
        ListNode* tmp=root;
        while(tmp->next->next!=NULL){
            tmp=tmp->next;
        }
        tmp->next=nullptr;
        free(tmp->next);
        return root;
    }
    ListNode* removeAtPos(ListNode* root,int pos){
        /*
        if the position is k==1 than remove the head wala fucntion
          removehead(root);
        if the position is equal to the length of the root than removetail
        wala fucntion
        removeTail(root);  
        */
        if(root==NULL){
            return root;
        }
        if(pos==1){
            root=root->next;
            return root;
        }
        int cnt=0;
        ListNode* tmp=root;
        ListNode* pr=NULL;
        while(tmp!=NULL){
            cnt++;
            if(cnt==pos){
               tmp->next=tmp->next->next;
               break;                
            }
            pr=tmp;
            tmp=tmp->next;
        }
        return root;
    }
    ListNode* removeElm(ListNode* root,int elm){
        if(root==NULL){
            return root;
        }
        if(root->val==elm){
            root=root->next;
            return root;
        }
        ListNode* tmp=root;
        ListNode* pr=NULL;
        while(tmp!=NULL){
            if(tmp->val==elm){
                pr->next=pr->next->next;
                break;
            }
            pr=tmp;
            tmp=tmp->next;
        }
        return root;
    }
};
int main(){
   vector<int> arr={1,2,3,4,5};
   Solution obj;
   ListNode* node=obj.arrtoll(arr);
   while(!node){
    cout<<node->val<<" ";
    node=node->next;
   }
}


