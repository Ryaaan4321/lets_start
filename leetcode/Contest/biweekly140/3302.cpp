#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    set<pair<int,pair<int,int>>>st;
    bool fucc(int i,int j,bool f,string &w1,string &w2,vector<int>ans){
        if(j>=w2.size())return 1;
        if(i>=w1.size())return 0;
        if(st.count({i,{j,f}}))return 0; 
        bool f1=0;
        if(w1[i]==w2[j]){
           f1=fucc(i+1,j+1,f,w1,w2,ans);
           if(f1){
            ans.push_back(i);
            return 1;
           }
        }else{
            if(f>0){
                f1=fucc(i+1,j+1,0,w1,w2,ans);
                if(f1){
                    ans.push_back(i);
                    return 1;
                }
            }
            while(i<w1.size() && w1[i]!=w2[j]){
                if(i<w1.size()){
                    f1=fucc(i+1,j+1,f,w1,w2,ans);
                    if(f1){
                        ans.push_back(i);
                        return 1;
                    }
                }
            }
        }
        st.insert({i,{j,f}});
        return f1;

    }
    vector<int> validSequence(string word1, string word2) {
     vector<int>ans;
     bool f=fucc(0,0,1,word1,word2,ans);
     if(f){
        reverse(begin(ans),end(ans));
        if(ans.size()==word2.size()){
            return ans;
        }
     }   
     return {};
    }
};