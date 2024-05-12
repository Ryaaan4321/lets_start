#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public:
    int maximumEnergy(vector<int>& a, int k) {
        int n=a.size();
        vector<int>dp(n+1);
        int mx=a[n-1];
        dp[n-1]=a[n-1];
        for(int i=n-2;i>=0;i++){
            dp[i]=a[i];
            if(i+k<n){
                dp[i]+=dp[i+k];
            }
            mx=max(mx,dp[i]);
        }
        return mx;
    }
};