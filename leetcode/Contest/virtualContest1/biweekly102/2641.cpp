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
    TreeNode* replaceValueInTree(TreeNode* root) {
       queue<TreeNode*>q;
       q.push(root);
       vector<int>levelsum;
       while (!q.empty())
       {
        int sz=q.size();
        int currsum=0;
        while(sz--){
        TreeNode* node=q.front();
        q.pop();
        currsum+=node->val;
        if(node->left){
            q.push(node->left);
        }
        if(node->right){
            q.push(node->right);
        }
        }
        levelsum.push_back(currsum);
       }
       for(int i=0;i<levelsum.size();i++){
        cout<<levelsum[i]<<endl;
       }
       q.push(root);
       int level=1;
       root->val=0;
       while(!q.empty()){
        int sz=q.size();
        while (sz--)
        {
            TreeNode* node=q.front();
            q.pop();
            int siblingsum=(node->left ? node->left->val : 0) + (node->right ? node->right->val : 0);
            if(node->left){
                node->left->val=levelsum[level]-siblingsum;
                q.push(node->left);
            }
            if(node->right){
                node->right->val=levelsum[level]-siblingsum;
                q.push(node->right);
            }
        }
        level++;
        
       }
       return root;
    }
};


class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int prevsum=root->val;
        while(!q.empty()){
            int sz=q.size();
            int curlevelsum=0;
            while(sz--){
                TreeNode* node=q.front();
                q.pop();
                node->val=prevsum-node->val;
                int siblingsum=(node->left?node->left->val:0)+(node->right?node->right->val:0);
                if(node->left){
                    curlevelsum+=node->left->val;
                    node->left->val=siblingsum;
                    q.push(node->left);
                }
                if(node->right){
                    curlevelsum+=node->right->val;
                    node->right->val=siblingsum;
                    q.push(node->right);
                }
            } 
            prevsum=curlevelsum;         
        }
        return root;
    }
};