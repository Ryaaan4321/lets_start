#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        if (nums1.size() & 1) {
            for (int i = 0; i < nums2.size(); i++) {
                ans = ans ^ nums2[i];
            }
        }
        if (nums2.size() & 1) {
            for (int i = 0; i < nums1.size(); i++) {
                ans = ans ^ nums1[i];
            }
        }
        return ans;
    }
};