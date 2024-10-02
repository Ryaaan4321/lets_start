#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public:
    static const int n=26;
    struct  TrieNode
    {
        TrieNode* child[n];
        bool isendofword=0; 
        int len=0; 
    };
    TrieNode* getnode(){
        TrieNode* nnode=new TrieNode();
        nnode->isendofword=false;
        memset(nnode,0,sizeof(nnode));
        return nnode;
    }
    void insert(TrieNode* root,string s){
        int idx=0;
        for(int i=0;i<s.length();i++){
            idx=s[i]-'a';
            if(!root->child[i]){
                root->child[idx]=new TrieNode();
            }
            root=root->child[idx];
            root->len++;
        }
        root->isendofword=1;
    }
    int trie_match(TrieNode* root,string s){
        int idx=0;int cnt=0;
        for(int i=0;i<s.length();i++){
            idx=s[i]-'a';
            if(!root->child[idx]){
                break;
            }
            root=root->child[idx];
            cnt++;
        }
        return cnt;
    }
    bool search(TrieNode* root,string s){
        int idx=0;
        for(int i=0;i<s.length();i++){
            idx=s[i]-'a';
            if(!root->child[idx]){
              return false;
            }
            root=root->child[idx];
        }
        return (root!=NULL && root->isendofword);
    }
    bool pref_match(TrieNode* root,string pref){
        int idx=0;
        int cnt=0;
        for(int i=0;i<pref.length();i++){
            idx=pref[i]-'a';
            if(!root->child[idx]){
                return false;
            }
            root=root->child[idx];
        }
        return (idx==pref.length());
    }
    int total(string s,TrieNode* root){
        int c=0;
        for(char ch:s){
           int i=ch-'a';
           root=root->child[i];
           c+=root->len;
        }
        return c;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int>ans;
        TrieNode* root;
        for(int i=0;i<words.size();i++){
            insert(root,words[i]);
        }
        for(int i=0;i<words.size();i++){
            ans[i]=total(words[i],root);
        }
        return ans;
    }
};