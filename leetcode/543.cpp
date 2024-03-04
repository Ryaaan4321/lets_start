#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};



class Solution {
public:

    int solve(TreeNode* root , int result){
        if(!root ){
            return 0;
        }
        int left=solve(root->left,result);
        int right=solve(root->right,result);

        result=max(result,+right);

        return result+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int result=INT_MIN;
        return solve(root,result);
    }
};