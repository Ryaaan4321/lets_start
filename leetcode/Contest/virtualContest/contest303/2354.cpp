#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int bitcount(int x)
    {
        int ans = 0;
        for (int j = 29; j >= 0; j--)
        {
            if ((1 << j) & x)
                ans++;
        }
        return ans;
    }
    long long countExcellentPairs(vector<int> &nums, int k)
    {
        set<int> st;
        for (auto i : nums)
            st.insert(i);
        vector<int> bits;
        for (auto i : st)
        {
            int cnt = bitcount(i);
            bits.push_back(cnt);
        }
        sort(bits.begin(), bits.end());
        int n = bits.size();
        int l = 0, r = n - 1;
        long long result = 0;
        while (l < n && r >= 0)
        {
            if (bits[l] + bits[r] < k)
            {
                l++;
            }
            else
            {
                result += (n - 1);
                r--;
            }
            
        }
        return result;
    }
};