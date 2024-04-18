// #include <bits/stdc++.h>
// #include <algorithm>
// #include <math.h>

// using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;

//     TreeNode(int x)
//     {
//         val = x;
//         left = right = NULL;
//     }
// };

// class Solution
// {
// public:
//     TreeNode *deleteNode(TreeNode *root, int key)
//     {
//         if(!root){
//             return NULL;
//         }
//         if(root->val==key){
//             return NULL;
//         }
//         queue<TreeNode*>q;
//         q.push(root);
//         while (!q.empty())
//         {
//             TreeNode* node=q.front();
//             q.pop();

//             TreeNode* left_child=node->left;
//             TreeNode* right_child=node->right;

//             if(node->val==key){
//                 node->left=left_child->left;
                
//             }

//         }
        
//     }
// };