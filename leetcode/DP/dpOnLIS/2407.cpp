#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;
// - https://leetcode.com/submissions/detail/1252048865/
class Solution
{
public:
    int solve(int idx, int pr, int k, int n, vector<int> &a,vector<vector<int>> &dp){
        if (idx == n){return 0;}
        if (dp[idx][pr+1] != -1){return dp[idx][pr+1];}

        int t=0;
        if (pr == -1 || (a[idx]>a[pr] && a[idx]-a[pr] <= k)) 
        {
            t=1+solve(idx+1,idx,k,n,a,dp);
        }
        int s=solve(idx+1,pr,k,n,a,dp);

        dp[idx][pr + 1] = max(t, s); 
        return dp[idx][pr+ 1]; 
    }
    int lengthOfLIS(vector<int> &a, int k)
    {
        int n = a.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return solve(0,-1,k,n,a,dp);
    }
};

