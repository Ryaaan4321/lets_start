#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left=right=nullptr;
    }
};

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        priority_queue<long long>pq;
        pq.push(root->val);
        q.push(root);
        while (!q.empty())
        {
            int sz=q.size();
            int sm=0;
            while(sz--){
                auto node=q.front();
                q.pop();
                sm+=node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            pq.push(sm);
        }
        if(pq.size()<k){
            return -1;
        }
        while(k--){
            pq.pop();
        }
        return pq.top();
    }
};