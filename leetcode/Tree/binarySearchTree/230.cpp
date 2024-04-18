#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;

    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    vector<int> ans;
    void inorder(TreeNode *root, int k)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left, k);
        ans.push_back(root->val);
        inorder(root->right, k);
    }
    void preorder(TreeNode *root, int k)
    {
        if (root == NULL)
        {
            return;
        }
        ans.push_back(root->val);
        preorder(root->left, k);
        preorder(root->right, k);

        /*or also

        if(root==NULL){
            return;
        }
        postorder(root->left,k);
        postorder(root->right,k);
        ans.push_back(root->val);

        the only thing is that is not ok here we will end up taking extra (Onlogn)
        tc becuase in both of these traversal the elements r not stored in a
        sorted manner so thats why i have used a inorder becuase it stores
        the elements in a sorted function and we can take advantage of that

        */
    }
    void inorder(TreeNode *root, int &counter, int k, int smallesK)
    {
        if (!root || counter == k)
        {
            return;
        }
        inorder(root->left, counter, k, smallesK);
        counter++;
        if (counter == k)
        {

            smallesK = root->val;
            return;
        }
        inorder(root->right, counter, k, smallesK);
    }
   
    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root, k);
        sort(ans.begin(), ans.end());
        return ans[k - 1];
    }
};