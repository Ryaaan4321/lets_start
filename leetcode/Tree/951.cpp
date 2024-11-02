#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        val = data;
        left = right = nullptr;
    }
};

// i have tried it by myself bt this can only pass (69/77) testcases not good bt not bad also
// ^_^   peace!

class Solution
{
public:
    vector<int> post1;
    vector<int> post2;
    void fucc1(TreeNode *root, vector<int> &a)
    {
        if (!root)
            return;
        if ((root->left == NULL) || (root->right == NULL))
        {
            a.push_back(-1);
        }
        fucc1(root->left, a);
        fucc1(root->right, a);
        a.push_back(root->val);
    }
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        fucc1(root1, post1);
        fucc1(root2, post2);
        sort(begin(post1), end(post1));
        sort(begin(post2), end(post2));
        bool f = 1;
        bool f1 = 1;
        if (post1.size() != post2.size())
        {
            f1 = 0;
        }
        for (int i = 0; i < min(post1.size(), post2.size()); i++)
        {
            if (post1[i] != post2[i])
            {
                f = 0;
                break;
            }
        }
        for (int i = 0; i < post1.size(); i++)
        {
            cout << post1[i] << ' ';
        }
        cout << endl;
        for (int i = 0; i < post2.size(); i++)
        {
            cout << post2[i] << ' ';
        }
        cout << endl;
        cout << f << ' ' << f1;
        return f & f1;
    }
};

class Solution
{
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        return (root1 == root2) ||
               (root1 && root2 && root1->val == root2->val &&
                ((flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
                 (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left))));
    }
};