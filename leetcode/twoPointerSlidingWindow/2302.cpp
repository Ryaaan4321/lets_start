#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sm=0;int n=nums.size();
        long long ans=0;int left=0;int right=0;
        while(right<n){
            sm+=nums[right];
            while(left<=right && sm*(right-left+1)>=k){
                sm-=nums[left];
                left++;
            }
            ans+=right-left+1;
            right++;
        }
        return ans;
    }
};