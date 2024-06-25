#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    typedef long long ll;
    vector<vector<ll>>dp;
    ll n;
    ll fucc(int i,bool f,vector<int>& nums){
        if(i>=n){
            return 0;
        }
        if(dp[i][f]!=-1){
            return dp[i][f];
        }
        ll _t=-1e15;
        ll _nt=-1e15;
        if(f==1){
            _nt=(-nums[i])+fucc(i+1,0,nums);
        }
        _t=nums[i]+fucc(i+1,1,nums);
        return dp[i][f]=max(_t,_nt);
    }
    long long maximumTotalCost(vector<int>& nums) {
        n=nums.size();
        dp.resize(n+1,vector<ll>(3,-1));
        return nums[0]+fucc(1,1,nums);
    }
};