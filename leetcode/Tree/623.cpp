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
        left = right = NULL;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *dfs(TreeNode *root, int val, int depth, int curr)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (curr == depth - 1)
        {
            TreeNode *leftTemp = root->left;
            TreeNode *rightTemp = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            root->left->left = leftTemp;
            root->right->right = rightTemp;

            return root;
        }
        root->left = dfs(root->left, val, depth, curr + 1);
        root->right = dfs(root->right, val, depth, curr + 1);

        return root;
    }
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        int curr = 1;
        return dfs(root, val, depth, curr);
    }
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        
    }
};
