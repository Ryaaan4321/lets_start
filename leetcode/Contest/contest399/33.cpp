#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        unordered_map<int, int> mpp;
        for (int num : nums2)
        {
            mpp[num]++;
        }

        long long cnt = 0;
        for (int num1 : nums1)
        {
            if (num1 % k == 0)
            {
                for (auto &it : mpp)
                {
                    if (it.first != 0 && num1 % (it.first * k) == 0)
                    {
                        cnt += it.second;
                    }
                }
            }
        }
        return cnt;
    }
    
};
