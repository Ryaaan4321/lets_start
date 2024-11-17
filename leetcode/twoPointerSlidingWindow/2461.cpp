#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sm = 0;
        long long ans = 0;
        int left = 0;
        int right = 0;
        int n = nums.size();
        map<int, int> mp;
        while (right < n) {
            if ((right - left + 1) < k) {
                mp[nums[right]]++;
                sm += nums[right];
                right++;
            } else if ((right - left + 1) == k) {
                mp[nums[right]]++;
                sm += nums[right];
                if (mp.size() == k) {
                    if (sm > ans) {
                        ans = sm;
                    }
                }
                if (mp[nums[left]] > 1) {
                    mp[nums[left]]--;
                } else {
                    mp.erase(nums[left]);
                }
                sm -= nums[left];
                left++;
                right++;
            }
        }
        return ans;
    }
};