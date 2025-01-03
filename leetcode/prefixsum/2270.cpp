#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long>pref(nums.size());
        pref[0]=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        int cnt=0;
        for(int i=0;i<n-1;i++){
           long long lsm=pref[i];
           long long rsm=pref[n-1]-pref[i];
           if(lsm>=rsm){
            cnt++;
           }
        }
        return cnt;
    }
};