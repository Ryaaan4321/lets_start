#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s;
        for(int i=1;i<n;i++){
            if(s.find(nums[i]+nums[i-1])!=s.end()){
                return 1;
            }
            s.insert(nums[i]+nums[i-1]);
        }
        return 0;
        
    }
};