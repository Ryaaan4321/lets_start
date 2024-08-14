#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

bool isprime(int N) {
    if (N <= 1) {
        return false;
    }
    for (int i = 2; i < N; i++) {
        if (N % i == 0) {
            return false;
        }
    }
    return true;
}
class Solution {
public:  
    int diagonalPrime(vector<vector<int>>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(isprime(nums[i][i]))ans=max(ans,nums[i][i]);
            if(isprime(nums[i][nums.size()-i-1]))ans=max(ans,nums[i][nums.size()-i-1]);
        }
        return ans;
    }
};