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
        left = NULL;
        right = NULL;
    }
};

class Solution
{
    vector<int> inorder(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
        return ans;
    }
    vector<int> preorder(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr)
        {
            return;
        }
        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
        return ans;
    }
    vector<int> postorder(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        ans.push_back(root->val);
        return ans;
    }
};