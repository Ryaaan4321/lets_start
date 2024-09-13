#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public:
    vector<int> xorQueries(vector<int>& a, vector<vector<int>>& grid) {
        int n=a.size();
        vector<int>ans(grid.size());
        vector<int>pref(n);
        pref[0]=a[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]^a[i];
        }
        for(int i=0;i<pref.size();i++){
            cout<<pref[i]<<' ';
        }
        for(int i=0;i<(int)grid.size();i++){
            int l=grid[i][0];
            int r=grid[i][1];
            if(l==0){
                ans[i]=pref[r];
            }else{
                ans[i]=pref[r]^pref[l-1];
            }
        }
        return ans;
    }
};