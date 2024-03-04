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
class Solution
{
public:
    bool leaf(TreeNode *root1, TreeNode *root2)
    {
        vector<int> leaves1;
        vector<int> leaves2;
        dfs(root1, leaves1);
        dfs(root2, leaves2);

        return leaves1 == leaves2;
    };

private:
    static void dfs(TreeNode *node, vector<int> leaves)
    {
        if (node == nullptr)
            return;
        dfs(node->left, leaves);
        dfs(node->right, leaves);

        if (!node->left && !node->right)
        {
            leaves.push_back(node->val);
        }
    }
};

signed main()
{
    int t;
    while (t-- > 0)
    {
        int t1, t2;
        cin >> t1 >> t2;

        TreeNode *root1 = new TreeNode(t1);
        TreeNode *root2 = new TreeNode(t2);

        root1->left = new TreeNode(4);
        root1->left->left = new TreeNode(3);
        root1->left->right = new TreeNode(4);
        root1->right = new TreeNode(5);
        root2->right->right = new TreeNode(3);
        root2->right->left = new TreeNode(4);

        Solution obj;
        bool ans = obj.leaf(root1, root2);

        cout << (ans ? "True" : "False") << endl;

        delete root1;
        delete root2;
    }

    return 0;
}
