#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        long long ans=0;
        map<int,int>mp;
        for(auto el:nums){
            long long gcd=__gcd(k,el);
            long long x=k/gcd;
            for(auto it:mp){
                if(it.first%x==0){
                    ans+=it.second;
                }
            }
            mp[gcd]++;
        }
        return ans;
    }
};