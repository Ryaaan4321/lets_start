#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next);
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        stack<ListNode*> st;
        ListNode* curr = head;
        while (curr)
        {
            st.push(curr);
            curr = curr->next;
            
        }

        int k = st.size() / 2;
        curr = head;
        while (k--)
        {

            ListNode *temp = curr->next;
            ListNode *topNoode = st.top();
            st.pop();
            curr->next = topNoode;
            topNoode->next = temp;
            curr = temp;
        }
        curr->next = nullptr;
    }
    /*2nd technique*/
};
