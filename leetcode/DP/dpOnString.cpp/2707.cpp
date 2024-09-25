#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int dp[52];
    int fucc(int i,set<string>&st,string &s,int &n){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int t=1+(fucc(i+1,st,s,n));
        for(int j=i;j<n;j++){
            string cur=s.substr(i,j-i+1);
            if(st.count(cur)){
                t=min(t,fucc(i+1,st,s,n));
            }
        }
        return dp[i]=t;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.length();
        memset(dp,-1,sizeof(dp));
        set<string>st(begin(dictionary),end(dictionary));
        int ans=fucc(0,st,s,n);
        return ans;
    }
};