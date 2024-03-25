#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        map<int,int> mp;
        for(int it:nums){
            mp[it]++;
        }
        vector<int> ans;
        for(auto it:mp){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};