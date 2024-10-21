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