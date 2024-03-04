#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution
{
    
    TreeNode *buildTree(vector<int>&inorder, int start, int end)
    {
        if (start > end)
            return NULL;

        int mid = start + (end - start) / 2;

        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = buildTree(inorder, start, mid - 1);
        root->right = buildTree(inorder, mid + 1, end);

        return root;
    }

public:
    
};