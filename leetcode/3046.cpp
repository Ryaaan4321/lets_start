#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPossibleToSplit(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (int num : nums)
        {
            map[num]++;
        }
        for (const auto &p : map)
        {
            if (p.second > 2)
            {
                return false;
            }
        }
        return true;
    }
    bool isPossibleToSplit1(vector<int> &nums)
    {
        sort(begin(nums), end(nums));
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i - 2] == nums[i])
                return false;
        }
        return true;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n); // Create a vector of size n

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // Read elements into the vector
    }

    Solution obj;
    obj.isPossibleToSplit(nums);

    bool ans = obj.isPossibleToSplit(nums);
    cout << ans ? "YES" : "NO";
    return 0;
}
