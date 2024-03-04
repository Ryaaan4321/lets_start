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
};

class Solution
{
public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        int count = 0;
        stack<pair<TreeNode *, int>> st;
        st.push({root, 0});

        while (!st.empty())
        {

            /**  auto [node, currentPath] = st.top();
             st.pop();*/
            /*we can use the value  explicitly rather than using the decomposed or this auto[...] lambda function
             values*/
            pair<TreeNode *, int> topPair = st.top();
            st.pop();

            TreeNode *node = topPair.first;
            int currentPath = topPair.second;

            if (node != nullptr)
            {
                currentPath = currentPath ^ (1 << node->val);

                if (node->left == nullptr && node->right == nullptr)
                {
                    if ((currentPath & (currentPath - 1)) == 0)
                    {
                        count++;
                    }
                }
                else
                {
                    st.push({node->right, currentPath});
                    st.push({node->left, currentPath});
                }
            }
        }
        return count;
    }
    /*2nd approach where we are using the map to store the frequency of the elements
    and in the palindrome only one elm can have a odd freq of lenght 1  and if there exist the freq more than that then we can
    cant call this palindrome and if there exist a string that contains the elements freq more than 1 than
    thats not a palindrome otherwise we cann call it palindrome
    for example-[1  ,2 ,1, 2 ,1]
    now here--
    freq[1]=3 , freq[2]=2 that is a palindrome
    and for that example-[1, 2 , 3 , 2 ,3]
    freq[1]=1,freq[3]=2 so now we have two oddelemets freq and that is clearly showing that it can form  a palindrome if it can be manipulated or the permuation of that array can be a palindrome
    something like
    [2 , 3 , 1 , 2 , 3]
    and another example we can take is - [1 , 2 ,3 , 4,2 , 1]
    now here -freq[1]=2;freq[1]=2;freq[3]=1;
    bt also the freq[4]=1 that means it can never form a palindrome
    e.g.1 2 1 => only 2 has odd frequency
    2 1 1 2 => no element has odd frequency
    3 2 1 2 3 => only 1 has odd frequency.*/

public:
    int isRequired(vector<int> map)
    {
        int oddcount = 0;
        for (auto it : map)
        {
            if (it % 2 == 1)
            {
                oddcount++;
            }
        }
        if (oddcount > 1)
            return 0;
        return 1;
    };
    int recur(TreeNode *curr, vector<int> &map)
    {
        if (!(curr->left) && !(curr->right)) /*so iterating in the tree along with the map vector to store the freq */
        {
            map[curr->val]++;
            int ans = isRequired(map); /*if we encounter value first time then freq then decrementing them*/
            map[curr->val]--;
            return ans;
        }
        map[curr->val]++; /*started with the incrementing the values*/
        int ans = 0;
        if (curr->left)
        {
            ans += recur(curr->left, map); /*the recursion will iterate in the left of th tree and increment the map values*/
        }
        if (curr->right) /*and the recursion will iterate in the right of th treee and increment the map values */
        {
            ans += recur(curr->right, map);
        }
        map[curr->val]--; /*and then again decrementing them*/
        return ans;
    }
    int pseudoPaindromicPaths(TreeNode *root)
    {
        vector<int> map(10, 0);
        return recur(root, map);
    }
};
