#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

struct ListNode{
    ListNode* next;
    int val;
    ListNode(int x){
        val=x;
        next=nullptr;
    }
};
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head){
            return nullptr;
        }
        vector<int>a;
        while(head!=nullptr){
            a.push_back(head->val);
            head=head->next;
        }
        sort(a.begin(),a.end());
        ListNode* root=new ListNode(a[0]);
        ListNode* pointer=root;
        for(int i=1;i<a.size();i++){
            ListNode* tmp=new ListNode(a[i]);
            pointer->next=tmp;
            pointer=pointer->next;
        }
        return root;
    }
};