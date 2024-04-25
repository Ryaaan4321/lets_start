#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int solve(int idx, int prev_idx, int k, int n, string s,
              vector<vector<int>> &dp)
    {
        if (idx == n)
        {
            return 0;
        }
        if (dp[idx][prev_idx] != -1)
        {
            return dp[idx][prev_idx];
        }
        if (abs((s[idx] - 'a') - (prev_idx)) <= k || prev_idx == 26)
        {
            dp[idx][prev_idx] =
                max(1 + solve(idx + 1, s[idx] - 'a', k, n, s, dp),
                    solve(idx + 1, prev_idx, k, n, s, dp));
        }
        else
        {
            dp[idx][prev_idx] = solve(idx + 1, prev_idx, k, n, s, dp);
        }
    }
    int longestIdealString2(string s,int k){
        int res=0;  
        int n=s.length();
        vector<int>dp(n+1,1);
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(abs(s[i]-s[j]<=k)){
                    dp[i]=max(res,dp[j]+1);
                }
            }
            res=max(res,dp[i]);
        }
    }
    int longestIdelString3(string s ,int k){
        int n=s.length();
        int res=0;
        vector<int>dp(26,0);
        for(int i=0;i<n;i++){
            int curr_char=s[i]-'a';
            int left=max(0,curr_char-k);
            int right=min(26,curr_char+k);
            int longest=0;
            for(int j=left;j<=right;j++){
                longest=max(longest,dp[j]);
            }
            dp[curr_char]=max(dp[curr_char],longest);
            res=max(res,dp[curr_char]);
        }
        return res;
    }

    int longestIdealString(string s, int k)
    {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(127, -1));
        int ans = solve(0, 26, k, n, s, dp);
        return ans;
    }
};