#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        map<int, int> freq;
        int n = nums.size();
        long long res = n;
        for (int i = 0; i < n; i++) {
            freq[nums[i]] = i;
        }
        sort(begin(nums),end(nums));
        for (int i = 1; i < n; i++) {
            if (freq[nums[i]] < freq[nums[i - 1]]) {
                res += n - i;
            }
        }
        return res;
    }
};