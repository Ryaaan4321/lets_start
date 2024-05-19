#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

class Solution
{
public:
    bool fucc(ListNode* node){
        map<int,int>mp;
        while(node!=NULL){
            mp[node->val]++;
            node=node->next;
        }
        int cnt=0;
        for(auto it:mp){
            if(it.second&1){
                cnt++;
            }
        }
        return cnt>1?0:1;
    }
    bool isPalindrome(ListNode *node)
    {
        return fucc(node);
        /*got wa on 83 testcase*/
    }
    /* but these worked;;*/
     bool fucc(ListNode* head) {
        ListNode* node = head;
        stack<int> st;
        while (node != NULL) {
            st.push(node->val);
            node = node->next;
        }
        node = head;
        while (node != NULL) {
            if (node->val != st.top()) {
                return 0;
            }
            st.pop();
            node = node->next;
        }
        return 1;
    }
    bool isPalindrome(ListNode* head) {
        if(!head)return 0;
        vector<int> a;
        ListNode* node = head;
        while (node != nullptr) {
            a.push_back(node->val);
            node = node->next;
        }
        int n = a.size();
        int last = n-1;
        for (int i = 0; i < n / 2; i++) {
            if (a[i] != a[last]) {
                return 0;
            }
            last--;
        }
        return 1;
    }
};