#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int len = INT_MAX;
        int left = 0;
        int right = 0;
        int n = nums.size();
        while (right < n) {
            int sm = 0;
            while (sm < k && right < n) {
                if (nums[right] < k) {
                    sm += nums[right];
                    right++;
                }
                left++;
                right++;
            }
            if (sm > k) {
                sm -= nums[left];
                left++;
                right++;
            }
            if (sm == k) {
                len = min(len, right - left);
                sm -= nums[left];
                left++;
                right++;
            }
        }
        return len == INT_MAX ? -1 : len;
    }
};

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }
        deque<int> dq;
        int res = INT_MAX;
        for (int i = 0; i <= n; i++) {
            while (!dq.empty() && pre[i] - pre[dq.front()] >= k) {
                if (res > i - dq.front()) {
                    res = i - dq.front();
                }
                dq.pop_front();
            }
            while (!dq.empty() && pre[dq.back()] >= pre[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return res == INT_MAX ? -1 : res;
    }
};