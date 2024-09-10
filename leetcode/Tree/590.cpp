#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>


using namespace std;

struct Node{
    int children;
    Node* left;
    Node* right;
    Node(int val){
        children=val;
        left=nullptr;
        right=nullptr;
    }
};

class Solution {
public:
    vector<int>ans;
    vector<int> postorder(Node* root) {
        if(!root){
            return ans;
        }
       
    }
};