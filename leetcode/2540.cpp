#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> st;
        for (auto it : nums1)
        {
            st.insert(it);
        }
        for (int it : nums2)
        {
            if (st.count(it) > 1)
            {
                return it;
            }
        }
        return -1;
    }
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        int pt1 = 0;
        int pt2 = 0;
        int n = nums1.size();
        int m = nums2.size();
        while (pt1 < n && pt2 < m)
        {
            if (nums1[pt1] == nums2[pt2])
                return nums1[pt1];
            else if (nums1[pt1] < nums2[pt2])
                pt1++;
            else
                pt2++;
            /* code */
        }

        return -1;
    }
};