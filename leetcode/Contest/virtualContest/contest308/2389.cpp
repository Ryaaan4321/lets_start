#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int binarysearch(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int mid;
        int idx = -1;

        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] <= target)
            {
                l = mid + 1;
                idx = mid;
            }
            else if (nums[mid] > target)
            {
                r = mid - 1;
            }
        }
        return idx + 1;
    };
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        int n = nums.size();
        sort(begin(nums), end(nums));
        for (int i = 1; i < n; i++)
        {
            nums[i] += nums[i - 1];
        }
        int m = queries.size();
        vector<int>ans(m);
        for (int i = 0; i < m; i++)
        {
            auto it=binarysearch(nums,queries[i]);
            ans[i]=it;
        }
        return ans;
    }
};