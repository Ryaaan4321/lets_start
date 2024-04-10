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
class Solution
{
public:
    int smallNumbers(TreeNode *root, string ans)
    {
        if (!root)
        {
            return 0;
        }
        ans += to_string(root->val);
        int left = smallNumbers(root->left, ans);
        int right = smallNumbers(root->right, ans);

        return left + right;
    }
};
