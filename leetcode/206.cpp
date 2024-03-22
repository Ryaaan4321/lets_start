#include <bits/stdc++.h>
#include<algorithm>
#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode *next):val(x),next(next){}

};
class Solution{
    ListNode* reverseList(ListNode* head){
        ListNode* temp=nullptr;
        while (head!=nullptr)
        {
            ListNode* next=head->next;
            head->next=temp;
            temp=head;
            head=next;
            /* code */
        }
        return temp;
        
    }
    

};