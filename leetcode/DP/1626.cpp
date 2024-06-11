#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int>& s, vector<int>& a) {
        vector<pair<int,int>>vp;
        int n=a.size();
        vector<int>dp(n+1);
        int sm=0;
        for(int i=0;i<n;i++){
            vp.push_back({a[i],s[i]});
        }
        sort(vp.begin(),vp.end());
        for(int i=0;i<n;i++){
            dp[i]=vp[i].second;
            for(int j=0;j<i;j++){
                if(vp[j].second <=vp[i].second){
                    dp[i]=max(dp[i],dp[j]+vp[i].second);
                }
            }
            sm=max(sm,dp[i]);
        }
        return sm;
    }
};