#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return nums[0]; 

        int mx = abs(nums[n - 1] - nums[0]); 
        for (int i = 1; i < n; i++) { 
            mx = max(mx, abs(nums[i - 1] - nums[i]));
        }
        return mx;
    }
};
