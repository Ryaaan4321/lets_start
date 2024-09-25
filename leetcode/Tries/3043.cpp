#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>


using namespace std;

class Solution {
public:
    struct TrieNode{
        TrieNode *child[10];
        TrieNode(){
            for(int i=0;i<10;i++){
                child[i]=NULL;
            }
        }
    };
    void trie_insert(TrieNode* root,string s){
        int idx=0;
        for(int i=0;s[i]!='\0';i++){
            idx=s[i]-'0';
            if(root->child[idx]==NULL){
                root->child[idx]=new TrieNode();
            }
            root=root->child[idx];
        }
    }
    int trie_match(TrieNode* root,string s){
        int idx=0;
        int cnt=0;
        for(int i=0;s[i]!='\0';i++){
            idx=s[i]-'0';
            if(!root->child[idx]){
                break;
            }
            root=root->child[idx];
            cnt++;
        }
        return cnt;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root=new TrieNode();
        string str="";
        for(int elm:arr1){
            str=to_string(elm);
            trie_insert(root,str);
        }
        int mxlen=0;
        for(int elm:arr2){
            str=to_string(elm);
            int t=trie_match(root,str);
            mxlen=max(mxlen,t);
        }
        return mxlen;
    }
};