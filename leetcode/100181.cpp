#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    int minimumCost(vector<int> &nums)
    {
        int sum=0;
        for(int i=0;i<nums.size();++i){
            if(nums.size()<=3){
                sum+=nums[i];
            }else if(nums.size()>3){
                for(int i=0;i<nums.size();++i){
                    sum+=nums[i];
                }
            }
        }
        return sum;
    }
};
signed main()
{
    int n;
    cin>> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    Solution obj;
    int ans=obj.minimumCost(a);
    cout<< ans<<endl;

    return 0;
};