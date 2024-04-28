#include <bits/stdc++.h>
#include <algorithm>
#include <malloc.h>

using namespace std;

class Solution
{
public:
    int minimumAddedInteger(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int mn = INT_MAX;
        int n = nums2.size();
        int m = nums1.size();
        int diff = 0;
        int temp = 0;
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            min1 = min(min1, nums1[i]);
        }
        for (int i = 0; i < m; i++)
        {
            min2 = min(min2, nums2[i]);
        }

        return min1 - min2;

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         temp = nums1[j];
        //         diff = (nums2[i] - nums1[j]);
        //     }
        //     if(temp+nums1[])
        // }

        // return mn;
    }
};