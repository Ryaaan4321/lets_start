#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;
class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n=nums.size();int m=nums[0].size();
        for(int i=0;i<n;i++){
            sort(nums[i].begin(),nums[i].end());
        }
        int sm=0;
        for(int j=0;j<m;j++){
            int t=INT_MIN;
            for(int i=0;i<n;i++){
                t=max(t,nums[i][j]);
            }
            sm+=t;
        }
        return sm;
    }
};