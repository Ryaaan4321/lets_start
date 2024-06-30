#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


int solve(vector<int> a,int k){
    int n=a.size();
    int l=0;
    int r=0;
    int mx_len=0;
    int sm=0;
    while(r<n){
        sm+=a[l];
        if(sm>k){
           sm=sm-a[l];
           l=l+1;
        }
        if(sm<=k){
            mx_len=max(mx_len,r-l+1);
        }
        r=r+1;
    }
    return mx_len;
};