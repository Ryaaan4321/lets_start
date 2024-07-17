#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public:
    int dp[10000+5][2];
    int fucc(int i,bool f,vector<int>&a,int k){
        if(i==a.size()){
            return 1;
        }
        if(dp[i][f]!=-1){
            return dp[i][f];
        }
        int cnt=0;
        int t_=0;
        int nt_=0;
        if(f!=0 && k!=0){
            t_=fucc(i+1,0,a,k-1);
        }
        nt_=fucc(i+1,0,a,k);
        return dp[i][f]=max(t_,nt_);
    }
    int minCapability(vector<int>& a, int k) {
        memset(dp,-1,sizeof(dp));
        return fucc(0,1,a,k);
    }
};