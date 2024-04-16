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

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        string ans = "";
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                ans += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                ans += "NULL,";
            }
        }
        return ans;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!getline(ss, str, ',')) break;
            if (str != "NULL") {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }
            if (!getline(ss, str, ',')) break;
            if (str != "NULL") {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return root;
    }
};

