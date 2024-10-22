#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>


using namespace std;


struct TreeNode{
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
    int cnt=0;
    int fucc(TreeNode* root,int sm,int tar){
       if(!root)return 0;
       sm+=root->val;
       int ans=0;
       if(sm==tar){
         ans++;
       }
       return fucc(root->left,sm,tar)+fucc(root->right,sm,tar);
    }
    int pathSum(TreeNode* root, int tar) {
        if(!root)return 0;
        return fucc(root,0,tar)+pathSum(root->left,tar)+pathSum(root->right,tar);
    }
};
