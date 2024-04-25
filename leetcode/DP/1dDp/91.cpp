#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int dp[102];
    int fuc(int idx,string &s){
        if(idx==s.size()){
            return 1;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        if(s[idx]=='0'){
            return 0;
        }
        int result1=fuc(idx+1,s);
        int result2=0;
        if(idx+1 < s.size()){
            if(s[idx]=='1' || s[idx]=='2' && s[idx+1] <='6'){
               result2 = fuc(idx+2,s);
            }
        }
        return dp[idx]= result1+result2;
    }
    int numDecodings(string s) {
       memset(dp, -1, sizeof(dp));
       return fuc(0,s);
    }
    int numDecodings1(string s){
        int n=s.length();
        vector<int>dp(n+1,0);

        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                dp[i]=0;
            }else{
                dp[i]=dp[i+1];

                if(i+1<n){
                    if(dp[i+1]=='1' || dp[i+1]=='2' && dp[i+2]<='6'){
                        dp[i]+=dp[i+2];
                    }
                }
            }
        }
        return dp[0];
    }
};