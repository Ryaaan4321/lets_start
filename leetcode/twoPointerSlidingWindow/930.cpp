#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int>map;
        int currsum=0;
        map[0]=1;
        int result=0;
        for(int &num:nums){
            currsum+=num;
            int remaningsum=currsum-goal;
            if(map.find(remaningsum)!=map.end()){
                result+=map[remaningsum];

            }
            map[currsum]++;
        }
        return result;   
    }
};


class Solution {
public: 
    int fucc(vector<int>& nums,int goal){
        int n=nums.size();int ans=0;
        int sm=0;int left=0;int right=0;
        while(right<n){
            sm+=nums[right];
            while(sm>goal && left<=right)
            {
                sm-=nums[left];
                left++;
            }
            ans+=right-left+1;
            right++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (fucc(nums,goal)-fucc(nums,goal-1));
    }
};