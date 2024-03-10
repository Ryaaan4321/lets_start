#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> ans(2, vector<int>());
        vector<int> left;
        vector<int> right;
        for (auto i : nums1)
        {
            auto n = find(nums2.begin(), nums2.end(), i);
            if (n == nums2.end())
            {
                left.push_back(i);
            }
        }
        for (auto i : nums2)
        {
            auto n = find(nums1.begin(), nums1.begin(), i);
            if (n == nums1.end())
            {
                right.push_back(i);
            }
        }
        unordered_map<int, int> f1;

        for (auto a : left)
        {
            f1[a]++;
        }

        vector<int> l;
        for (auto b : f1)
        {
            l.push_back(b.first);
        }
        unordered_map<int, int> f2;
        for (auto a : right)
        {
            f2[a]++;
        }
        vector<int> r;
        for (auto b : f2)
        {
            r.push_back(b.first);
        }
        ans[0] = l;
        ans[1] = r;

        return ans;
    }
};