#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                mp[nums[i]]++;
            }
        }
        int temp=INT_MIN;
        for(auto it:mp){
            if(it.second>temp){
                temp=it.second;
            }
        }
        return (temp!=INT_MIN?temp:-1);


    }
};