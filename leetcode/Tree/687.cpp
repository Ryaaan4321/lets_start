#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


struct  TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        val=data;
        left=right=nullptr;
    }
};

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;
        int mx = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto node = q.front();
                q.pop();
                if (node->left) {
                    if (node->left->val == node->val) {
                        cnt++;
                        mx = max(cnt, mx);
                    }
                    q.push(node->left);
                }
                if (node->right) {
                    if (node->right->val == node->val) {
                        cnt++;
                        mx = max(cnt, mx);
                    }
                    q.push(node->right);
                }
            }
        }
        return mx;
    }
    // thats the code that got accepted bt the code that i have written above got wa heheheheheh 😃
    pair<int,int> fucc(TreeNode* root,int &ans){
        if(!root){
            return {1e9,0};
        }
        auto l=fucc(root->left,ans);
        auto r=fucc(root->right,ans);
        int lsm=0;int rsm=0;
        if(l.first==root->val){
            lsm+=l.second+1;
        }
        if(r.first==root->val){
            rsm+=r.second+1;
        }
        ans=max(ans,lsm+rsm);
        return {root->val,max(lsm,rsm)};
    }
    int longestUnivaluePath(TreeNode* root) {
        int ans=0;
        fucc(root,ans);
        return ans;
    }
};