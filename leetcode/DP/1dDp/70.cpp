#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int dp[46];
    int solve(int n){
        if(n<=3){
            return dp[n]=n;
        }
        if(n==1 || n==2){
            return dp[n]=n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int one=solve(n-1);
        int two=solve(n-2);

        return dp[n]=one+two;
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);

    }
};