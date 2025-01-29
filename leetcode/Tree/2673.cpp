#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int fucc(int i,int n,vector<int>&a,int ans){
        if(i>n)return 0;
        int left=fucc(2*i+1,n,a,ans);
        int right=fucc(2*i+2,n,a,ans);
        ans+=abs(left-right);
        return a[i]+max(left,right);
    }
    int minIncrements(int n, vector<int>& cost) {
        int ans=0;
        fucc(1,n,cost,ans);
        return ans;
    }
};