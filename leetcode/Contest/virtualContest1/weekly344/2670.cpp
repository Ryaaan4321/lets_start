#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>pref(n);
        vector<int>suff(n);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            pref[i]=mp.size();
        }
        mp.clear();
        for(int i=n-1;i>=0;i--){
            mp[nums[i]]++;
            suff[i]=mp.size();
        }
        for(int i=0;i<n-1;i++){
            pref[i]-=suff[i+1];
        }
        return pref;
    }
};