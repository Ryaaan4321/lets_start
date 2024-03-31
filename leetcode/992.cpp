#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
    int subarraysWithkDistinct(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0;
        int j = 0;

        int imax = 0;
        int ans = 0;
        unordered_map<int, int> map;
        while (j < n)
        {
            map[nums[j]]++;
            while (map.size() > k)
            {
                if (nums[i] == 0)
                {
                    map[nums[i]]--;
                    map.erase(nums[i]);
                    /* code */
                }
                i++;
                imax = i;
            }
            while (map[nums[i]] > 1)
            {
                map[nums[i]]--;
                i++;
                /* code */
            }
            if (map.size() > k)
            {
                ans += (1 + i - imax);
            }
            j++;

            /* code */
        }
        return ans;
    }
    
};