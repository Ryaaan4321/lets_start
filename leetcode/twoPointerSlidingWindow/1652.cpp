#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>ans(n);
        if(k==0)return ans;
        int start=1;int end=k;int sm=0;
        if(k<0){
           start=n-abs(k);
           end=n-1;
        }
        for(int i=start;i<=end;i++)sm+=code[i];
        for(int i=0;i<n;i++){
            ans[i]=sm;
            sm-=code[start%n];
            sm+=code[(end+1)%n];
            start++;end++;
        }
        return ans;
        
    }
};