#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;

struct TreeNode
{

    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    /* data */
};

class Solution
{
public:
    int maxDepth;
    int bottomLeft;
    void dfs(TreeNode *root, int currentDepth)
    {
        if (!root)
        {
            return;
        }
        if (currentDepth > maxDepth)
        {
            maxDepth = currentDepth;
            bottomLeft = root->val;
        }
        dfs(root->left, currentDepth + 1);
        dfs(root->right, currentDepth + 1);
    }
    int findBottomLeftValue(TreeNode *root)
    {
        maxDepth = -1e9;

        dfs(root, 0);
    }

    /*breadth first search*/
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;
        int bottomLeft;
        while (!q.empty())
        {
            TreeNode *currNode = q.front();
            q.pop();
            bottomLeft = currNode->val;
            if (currNode->right)
            {
                q.push(currNode->right);
            }
            if (currNode->left)
            {
                q.push(currNode->left);
            }
            /* code */
        }
        return bottomLeft;
    }
    /*level order breadth first search*/

    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;
        int bottomLeft;
        q.push(root);
        while (!q.empty())
        {

            int level = q.size();
            while (level--)
            {
                TreeNode *currNode = q.front();
                q.pop();
                bottomLeft = currNode->val;

                if (currNode->right)
                {
                    q.push(currNode->right);
                }
                if (currNode->left)
                {
                    q.push(currNode->left);
                }
            }

            /* code */
        }
        return bottomLeft;
    }
};
