#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


struct ListNode{
    int val;
    ListNode *next;
    ListNode (int x){
        val=x;
        next=NULL;
    }
};

class Solution {
public:
    int gc(int a, int b) {
        // return std::_gcd(a,b);
        // i dont know hy this _gcd is not working take a look at it if u are 
        // wokrin again with this
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* first=head;
        ListNode* second=head->next;
        while(second!=NULL){
            int v=gc(first->val,second->val);
            ListNode* nnode=new ListNode(v);
            first->next=nnode;
            nnode->next=second;
            first=nnode->next;
            second=second->next;
        }
        return head;
    }
};