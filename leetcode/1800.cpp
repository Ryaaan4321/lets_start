#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sm=nums[0];int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                ans+=nums[i];
            }else {
                sm=max(ans,sm);
                ans=nums[i];
            }
        }
        return max(sm,ans);
    }
};