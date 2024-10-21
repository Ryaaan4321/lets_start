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
    int fucc(TreeNode* root,priority_queue<int>&pq){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            pq.push(1);
            return 1;
        }
        int ltree=fucc(root->left,pq);
        int rtree=fucc(root->right,pq);
        if(ltree!=0 && rtree!=0 && ltree==rtree){
            int res=ltree+rtree+1;
            pq.push(res);
            return res;
        }
        return 0;
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        priority_queue<int>pq;
        fucc(root,pq);
        int ans=0;
        while(!pq.empty() &&  k--){
            pq.pop();
        }
        if(k>0){
            return -1;
        }
        return pq.top();
    }
};