#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;
class Trie {
public:
    static const int n=26;
    struct TrieNode { 
        TrieNode *children[n]; 
        bool isEndOfWord; 
        int len=0;
    };
    TrieNode* getNode() {
        TrieNode* newnode = new TrieNode();
        newnode->isEndOfWord = false;
        memset(newnode,0,sizeof(newnode));
        return newnode;
    }
    /** Initialize your data structure here. */
    TrieNode* root;
    
    Trie() {
        root = getNode();
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *pointer = root; 
        
        for (int i = 0; i < word.length(); i++) { 
            int index = word[i] - 'a'; 
            if (!pointer->children[index]) 
                pointer->children[index] = getNode();
            
            pointer = pointer->children[index]; 
        }
        pointer->isEndOfWord = true; 
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *pointer = root; 
        
        for (int i = 0; i < word.length(); i++) { 
            int index = word[i] - 'a'; 
            if (!pointer->children[index]) 
                return false; 
            pointer = pointer->children[index]; 
        }
        return (pointer != NULL && pointer->isEndOfWord); 
        // if(pointer!=NULL && pointer->isEndOfWord==true){
        //     return true;
        // }
        // return false;
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *Pointer = root;
        int i = 0;
        for (i = 0; i < prefix.length(); i++) { 
            int index = prefix[i] - 'a'; 
            
            if (!Pointer->children[index]) 
                return false; 
            
            Pointer = Pointer->children[index]; 
        }
        if(i==prefix.length())
            return true;
        return false;
    }
};