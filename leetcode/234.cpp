#include <bits/stdc++.h>
#include<algorithm>
#include<iostream>

using namespace std;

struct  ListNode
{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode *next):val(x),next(next){}
    /* data */
};


class Solution {
public:
    /*vivek bhai ese smjha dijiye*/
    bool increaseFrequency(ListNode* head) {
    unordered_map<int,int>mpp;
    ListNode* current = head;
    /*mene ye logic lgaaya hai ki agr kisi bhi element ki frequency*/

    
    while (current) {
        
        mpp[current->val]++;

        current = current->next;
    }
    int cnt=0;
    for(auto &it:mpp){
        if(it.second&1){
            cnt++;
        }

    }
    if(cnt>1){
        return false;
    }
    return true;


    
}
    bool isPalindrome(ListNode* head) {
        bool ans=increaseFrequency(head);   
        return ans; 
    }
};
