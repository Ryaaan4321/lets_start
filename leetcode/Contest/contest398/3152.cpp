#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& grid) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1];
            if ((nums[i] & 1) == (nums[i - 1] & 1)) {
                prefix[i]++;
            }
        }
        vector<bool> ans;
        for (auto& q : grid) {
            int left = q[0], right = q[1];
            int specialCount = prefix[right] - (left > 0 ? prefix[left] : 0);
            ans.push_back(specialCount == 0);
        }
        return ans;
    }
};