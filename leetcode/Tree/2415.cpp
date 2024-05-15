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
    void fuc(TreeNode* l, TreeNode* r, int lev) {
        if (!l || !r)
            return;
        if (lev&1) {
            swap(l->val, r->val);
        }
        lev++;
        fuc(l->left, r->right, lev);
        fuc(l->right, r->left, lev);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        fuc(root->left, root->right, 1);
        return root;
    }
};;