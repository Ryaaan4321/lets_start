#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>


using namespace std;


class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
      int n=grid.size();
      vector<int>ans(n);
      for(int i=0;i<n;i++){
        int x=grid[i][0];
        string ss=to_string(x);
        ans[i]=(int)ss.size();
      }  
      int mn=INT_MAX;
      for(int i=0;i<ans.size();i++){
        if(mn>ans[i]){
            mn=ans[i];
        }
      }
      return ans;
    }
};