#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;
// struct Trie for N alphabets
const int N=26;
struct Trie {
    Trie* next[N];
    bool isEnd = 0;

    Trie() {
        fill(next, next+N, (Trie*)NULL);
    }

    ~Trie() {
    //    cout<<"Destructor\n";
        for (int i=0; i<N; ++i) {
            if (next[i] !=NULL) {
                delete next[i];
            }
        }
    }

    void insert(string& word) {
        Trie* Node=this;
        for(char c: word){
            int i=c-'a';
            if(Node->next[i]==NULL)
                Node->next[i]=new Trie();
            Node=Node->next[i];
        }
        Node->isEnd=1;
    }
};
class Solution {
public:
    Trie trie;
    bool start_with(string& w){
        Trie* Node=&trie;
        for( char c: w){
            int i=c-'a';
            if (Node->next[i]==NULL) return 0;
            Node=Node->next[i];
            if (Node->isEnd) return 1;
        }
        return 0;
    }
    int prefixCount(vector<string>& words, string& pref) {
        trie.insert(pref);
        int cnt=0;
        for(string& w: words)
            cnt+=start_with(w);
        return cnt;
    }
};