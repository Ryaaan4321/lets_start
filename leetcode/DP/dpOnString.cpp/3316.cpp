#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public:
    int dp[1000+3][1000+3];
    int fucc(int i,int j,string s,string t,vector<int>&a){
        if(j==t.length()){
            return 1;
        }
        set<int>st(begin(a),end(a));
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take=0;
        int ntake=0;
        if(s[i]==t[j]){
            take=1+fucc(i+1,j+1,s,t,a);
        }else if(s[i]!=t[j]){
            take=fucc(i+1,j,s,t,a);
        }else{
            if(st.count(i)){
                ntake=1+fucc(i+1,j,s,s,a);
            }
        }
        dp[i][j]=max(take,ntake);
        return dp[(s.length())][(t.length())];     
    }
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        memset(dp,-1,sizeof(dp));
        return fucc(0,0,source,pattern,targetIndices);
    }
};