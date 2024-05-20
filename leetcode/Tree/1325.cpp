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
    unordered_map<TreeNode*, TreeNode*> parent;
    void findparent(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        if (node->left) {
            parent[node->left] = node;
            findparent(node->left);
        }
        if (node->right) {
            parent[node->right] = node;
            findparent(node->right);
        }
    }
    TreeNode* removeLeafNodes(TreeNode* node, int t) {
        if (node == NULL) {
            return nullptr;
        }
        // findparent(node);
        node->left = removeLeafNodes(node->left, t);
        node->right = removeLeafNodes(node->right, t);

        if (!node->left && !node->right && node->val == t) {
            return nullptr;
        }
        return node;
    }
};