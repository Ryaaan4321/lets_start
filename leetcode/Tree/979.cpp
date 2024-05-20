#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left=right=nullptr;
    }
};

class Solution {
public:
    int cnt = 0;
    int fucc(TreeNode* node) {
        if (!node) {
            return 0;
        }
        int lft = fucc(node->left);
        int rgt = fucc(node->right);
        cnt += abs(lft) + abs(rgt);
        return node->val + lft + rgt - 1;
    }
    int distributeCoins(TreeNode* root) {
        fucc(root);
        return cnt;
    }
};
