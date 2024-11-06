#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canSortArray(vector<int>& nums) {

        int n=nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (__builtin_popcount(nums[j]) == __builtin_popcount(nums[j+1]) && nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
         for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return false;  
            }
        }
        return true;  
    }
};