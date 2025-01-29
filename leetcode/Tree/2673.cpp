#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int ans=0;
    int fucc(int i,int n,vector<int>&a){
        if(i>n)return 0;
        int left=fucc(i*2,n,a);
        int right=fucc(i*2+1,n,a);
        ans+=abs(left-right);
        return a[i-1]+max(left,right);
    }
    int minIncrements(int n, vector<int>& cost) {
        fucc(1,n,cost);
        return ans;
    }
};