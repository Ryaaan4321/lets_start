#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cntofodd=0;
        int left=0;int right=0;
        int ans=0;int n=nums.size();
        while(right<n){
            if(nums[right]&1){
                cntofodd++;
            }
            if(cntofodd==k){
                ans+=1;
            }
            while(cntofodd<k && left<=right){
                if(nums[left]&1){
                    cntofodd--;
                    left++;
                }
            }
            right++;
        }
        return ans;
    }
};