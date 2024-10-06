#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>


using namespace std;


class Solution {
public:
    int wiggleMaxLength(vector<int>& a) {
        int f = -1;
        int cnt = 1;
        for (int _ = 0; _ < (int)a.size() - 1; _++) {
            if (a[_] > a[_ + 1]) {
                if (f == -1 || f == 1) {
                    f = 0;
                    cnt++;
                }
            } else if (a[_] < a[_ + 1]) {
                if (f == -1 || f == 0) {
                    f = 1;
                    cnt++;
                }
            }
        }
        return cnt;
        /* bodmoshi ni karega madarchood*/
    }
};

class Solution {
public:
    int fucc(int idx,int pidx,int dif,int n,vector<int>&a,vector<vector<vector<int>>>&dp){
        if(idx==n){
            return 0;
        }
        if(dp[idx][pidx+1][dif]!=-1){
            return dp[idx][pidx+1][dif];
        }
        int take=INT_MIN;
        if((pidx==-1 || (dif==0 && a[pidx]>a[idx])) || (pidx==-1 || (dif==1 && a[pidx]<a[idx]))){
            take=1+fucc(idx+1,idx,!dif,n,a,dp);
        }
        int ntake=0+fucc(idx+1,pidx,dif,n,a,dp);
        return dp[idx][pidx+1][dif]=max(take,ntake);
    }
    int wiggleMaxLength(vector<int>&a) {
        int n=a.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n+2,vector<int>(3,-1)));
        return max(fucc(0,-1,0,n,a,dp),fucc(0,-1,1,n,a,dp));
    }
};