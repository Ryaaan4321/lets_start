#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int addedInteger(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int x = 0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for (int i = 0; i < n; i++)
        {
            x = nums2[i]-nums1[i];
        }
        return x;
    }
};
