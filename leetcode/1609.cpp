#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *prev;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

/*A binary tree is named Even-Odd if it meets the following conditions:

The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.*/

class Solution
{
public:
    bool isEvenOddTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        bool even_level = true;
        /*that even level will tell us that the levl is odd or the even*/
        while (!q.empty())
        {
            int level = q.size();
            int prev;//to store the prev value and comparing the value 
            if (even_level)
            {
                prev = INT_MIN;//as per problem descreption says for even the min value
            }
            if (!even_level)
            {
                prev = INT_MAX;//for odd it is the max value
            }
            while (level--)//the same shit of level order traversal
            {
                TreeNode *curr = q.front();
                q.pop();
                if (even_level && (curr->val % 2 == 0 || curr->val <= prev))
                {
                    return false;
                }
                if (!even_level && (curr->val % 2 != 0 || curr->val >= prev))
                {
                    return false;
                }
                prev = curr->val;

                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
                /* code */
            }
            even_level = !even_level;//once the even level is done then it willl help us to naviagate in the odd level or vice versa

            /* code */
        }
        return true;
    }
};