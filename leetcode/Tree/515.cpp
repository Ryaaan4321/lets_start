#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>


using namespace std;


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty()){
            int sz=q.size();
            int mx=INT_MIN;
            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();
                mx=max(mx,node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(mx);
        }
        return ans;
    }
};