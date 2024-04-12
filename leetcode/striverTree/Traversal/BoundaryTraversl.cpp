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
class Solution
{
public:
    bool isLeaf(TreeNode *root)
    {
        return !root->left && !root->right;
    };
    void addLeft(TreeNode *root, vector<int> &result)
    {
        TreeNode *curr = root;
        while (curr)
        {
            if (!isLeaf(curr))
            {
                result.push_back(curr->val);
            }
            if (curr->left)
            {
                curr = curr->left;
            }
            if (curr->right)
            {
                curr = curr->right;
            }
        }
    }
    void addRight(TreeNode *root, vector<int> &result)
    {
        TreeNode *curr = root;
        vector<int> temp;
        while (curr)
        {
            if (!isLeaf(curr))
            {
                result.push_back(curr->val);
            }
            if (curr->right)
            {
                curr = curr->right;
            }
            if (curr->left)
            {
                curr = curr->left;
            }
            /* code */
        }
        sort(temp.rbegin(), temp.rend());
        for (int it : temp)
        {
            result.push_back(it);
        }
    }
    void addLeaves(TreeNode *root, vector<int> &result)
    {
        TreeNode *curr = root;
        if (isLeaf(curr))
        {
            result.push_back(curr->val);
        }
        if (curr->left)
        {
            addLeaves(curr->left, result);
        }
        if (curr->right)
        {
            addLeaves(curr->right, result);
        }
    }
    vector<int> boundary(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
        {
            return ans;
        }
        if (!isLeaf(root))
        {
            ans.push_back(root->val);
        }
        addLeft(root, ans);
        addLeaves(root, ans);
        addRight(root, ans);
        return ans;
    }
};