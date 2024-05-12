#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;
class Solution
{
    vector<int> fuc(vector<int> a)
    {
        int n=a.size();
        int last[32]={};
        vector<int>ans(n,1);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<32;j++){
                if(a[i]&1<<j){
                    last[j]=i;
                }
                ans[i]=max(ans[i],last[j]-i+1);
            }
        }
        return ans;
    }
};