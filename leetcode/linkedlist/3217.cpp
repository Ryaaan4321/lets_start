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
    ListNode* modifiedList(vector<int>& a, ListNode* head) {
        vector<pair<ListNode*,bool>>vp;
        map<int,int>mp;
        for(int i=0;i<a.size();i++){
            mp[a[i]]++;
        }
        ListNode* tmp=head;
        while(tmp!=NULL){
            if(mp.count(tmp->val)){
               vp.push_back({tmp,1});
            }
            tmp=tmp->next;
        }
        tmp=vp[0].first;
        for(int i=1;i<=vp.size();i++){
            tmp->next=vp[i].first;
        }
        return tmp;
    }  
};