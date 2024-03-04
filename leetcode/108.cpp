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

class Solution{
public:
    TreeNode* maketree(vector<int> &nums, int low, int high)
    {
        if (low > high){
            return NULL;
        }

        int mid = low + (high - low) / 2;

        TreeNode* node = new TreeNode(nums[mid]);
        node->left = maketree(nums, low, mid - 1);
        node->right = maketree(nums, mid + 1, high);

        return node;
    }
    TreeNode* sortedArrayBST(vector<int> &nums)
    {
        return maketree(nums, 0, nums.size() - 1);
    }
};