#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        left=right=nullptr;
        val=x;
    }

};


class Solution {
public:
    vector<int> in;
    void inorder(TreeNode* node) {
        if (node == NULL)
            return;
        inorder(node->left);
        in.push_back(node->val);
        inorder(node->right);
    }
    vector<int> search(int x, int lo_, int hi_) {
        int mini = -1, maxi = -1;
        while (lo_ <= hi_) {
            int mid = lo_ + (hi_ - lo_) / 2;

            if (in[mid] == x)
                return {in[mid], in[mid]};

            if (in[mid] < x) {
                lo_ = mid + 1;
                mini = in[mid];
            } else {
                hi_ = mid - 1;
                maxi = in[mid];
            }
        }

        return {mini, maxi};
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& q) {
        inorder(root);
        vector<vector<int>> ans;
        for (int i = 0; i < q.size(); i++) {
            ans.push_back(search(q[i], 0, in.size() - 1));
        }
        return ans;
    }
};