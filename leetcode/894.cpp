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
    unordered_map<int, vector<TreeNode *>> mpp;
    vector<TreeNode *> solve(int n)
    {
        if (n % 2 == 0)
        {
            return {};
        }
        if (n == 1)
        {
            TreeNode *root = new TreeNode(0);
            return {root};
        }
        if (mpp.find(n) != mpp.end())
        {
            return mpp[n];//memoized the n and checked if it is precomputed than take the value from here and if not 
            //then compute it and put it out;
        }
        vector<TreeNode *> ans;
        for (int i = 1; i < n; i += 2)
        {
            vector<TreeNode *> leftBinaryTree = solve(i);
            /*suppose i have n = 5 than we know only odd number can form the full 
            binary tree so we started from the index 1 and the only index we will have is 1 umm i think i need to make
            audio editorail of this so lets do this becuasr typing this much makes me feel so fucked up*/
            
            vector<TreeNode *> rightBinartyTree = solve(n - i - 1);

            for (auto &l : leftBinaryTree)
            {
                for (auto &r : rightBinartyTree)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return mpp[n] = ans;
    }
    vector<TreeNode *> allPossibleFBT(int n)
    {
        return solve(n);
    }
};