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
{ /*so to solve this question we are converting this tree into the graph why so because we can easily traverse in the graph in the level order
   so thats why we are transforming this tree into the graph and hence for that we require a treenode's node , parent of it and the unordered map to store the values of that converted graph
   and now starting from the start  if at any point the node == nullptr then return there is not point move forward and to convert this tree into the graph
   i am using deapth first search haha ;*/
    void convert(TreeNode *node, int parent, unordered_map<int, vector<int>> &graph)
    {
        if (node == nullptr)
            return;

        vector<int> &adjacentList = graph[node->val];
        if (parent != 0)
        /*if the node  is not 0 then it can be a parent
        so pushing it in to the adjcacenlist*/
        {
            adjacentList.push_back(parent);
        }
        if (node->left != nullptr) // if the left point is not null then push_back it into the adjlist;
        {
            adjacentList.push_back(node->left->val);
        }
        if (node->right != nullptr) // same goes for the right  we have permormed  if it is not null then push_back it into the adjlist;
        {
            adjacentList.push_back(node->right->val);
        }
        convert(node->left, node->val, graph);  // now convert the left subtree them into the graph;
        convert(node->right, node->val, graph); // now also convert this right subtree into the right;
    }

    int amountOftime(TreeNode *root, int start)
    {
        unordered_map<int, vector<int>> graph; /*so now coming in our main function so here  i have taken the unordered map to convert  that tree into the graph*/
        convert(root, 0, graph);               // convert that tree into the graph by caaling that func;
        queue<int> q;                          // taking the queue the standard bfs traversal
        q.push(start);                         // pushed the start value into the queue
        int minute = 0;
        unordered_set<int> visited; // and if u have done the bfs traversal than visited is the array or unordered set which keeps a check that either the node is visited or not if it is
        /* visited then it will be also marked in the visited arr or set  and if it is visited then there is no need to go further  in that  graph */
        visited.insert(start);
        while (!q.empty()) // standard bfs traversal
        {
            int size = q.size(); // because we are going to perform the traversal in the level order so thats why so thats why i have taken the size
            while (size--)
            { /*and now we are performing the level order traversal*/
                int node = q.front();
                q.pop();
                for (int child : graph[node])
                {
                    if (visited.find(child) == visited.end())
                    { /*and if they are equal then then push thm into the visited and also into the queue;*/
                        visited.insert(child);
                        q.push(child);
                    }
                }
            }
            minute++; // once we got this then incrementing the minute ;
            /* code */
        }
        return minute - 1; /*and becuase when we start the traversal then the start node will also get counted so thats why to returning -1*/
    }
};