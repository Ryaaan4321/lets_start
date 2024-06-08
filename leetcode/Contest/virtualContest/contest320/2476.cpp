#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = right = nullptr;
    }
};
class Solution{
    public:
    vector<int>in;
    void inorder(TreeNode* node){
        if(node==NULL){return;}
        inorder(node->left);
        in.push_back(node->val);
        inorder(node->right);
    }
    vector<int> search(int _lo,int _hi,int x){
        int _mn=-1;
        int _mx=-1;
        while(_lo<=_hi){
            int mid=_lo+(_hi-_lo)/2;
            if(in[mid]==x){
                return {in[mid],in[mid]};
            }
            if(in[mid]<x){
                _lo=mid+1;
                _mn=in[mid];
            }else{
                _hi=mid-1;
                _mx=in[mid];
            }
        }
        return {_mn,_mx};
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& q) {
        inorder(root);
        vector<vector<int>>ans;
        for(int i=0;i<q.size();i++){
             ans.push_back(search(0,q.size()-1,q[i]));
        }
        return ans;
    }

};