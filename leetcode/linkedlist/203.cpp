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
    ListNode* removeElements(ListNode* head, int data) {
        vector<pair<ListNode*,bool>>vp;
        ListNode* cur=head;
        while(cur!=nullptr){
            if(cur->val==data){
                vp.push_back({cur,0});
            }
            vp.push_back({cur,1});
        }
        for(auto it:vp){
            cout<<it.first<<' '<<it.second<<endl;
        }
    }
};