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
class Solution {
public:
    bool isleaf(TreeNode* root) { return !root->left && !root->right; }
    bool evaluateTree(TreeNode* root) {
        if (root->val == 0) {
            return 0;
        }
        if (root->val == 1) {
            return 1;
        }
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);
        if (root->val == 2) {
            return left || right;
        }
        if (root->val == 3) {
            return left && right;
        }
        return 0;
    }
};