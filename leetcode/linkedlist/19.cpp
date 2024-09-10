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

class Solution{
    public:
    ListNode* removeNthFromEnd(ListNode* head,int n){
        ListNode* tmp=new ListNode(0);
        tmp->next=head;
        ListNode* fast=head;
        ListNode* slow=head;

        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        while(fast!=nullptr){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return tmp->next;
    }
    int removeDuplicates(vector<int>& nums) {
       set<int>st(nums.begin(),nums.end());
       return st.size();
       vector<int>ans((int)st.size());
       for(int i=0;i<st.size();i++){
        ans.push_back(*st.rbegin());
        st.erase(*st.rbegin());
       }
    //    return 1; glt hai dekh liyoek bar
    }

};