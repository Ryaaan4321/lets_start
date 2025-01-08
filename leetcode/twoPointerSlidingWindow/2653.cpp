#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int find(map<int, int> &m, int x)
    {int c=0;
        for(auto i:m){
             c+=i.second;//Incrementing counter to point to the corresponding elment in our key-value pair
            if(c>=x) //This means that the 'x' element is present so we return it
                return i.first;
           
        }
        return INT_MAX; // 'x' the smallest element not in our window
    }
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x)
    {
        int n=nums.size();
        map<int,int>mp;
        int i=0;
        vector<int>ans;
        for(int j=0;j<n;j++){
            mp[nums[j]]++;
            while((j-i)+1 >k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
            }
            i++;
            if((j-i+1)==k){
              int mn=find(mp,x);
              if(mn==INT_MAX || mn>0){
                ans.push_back(0);
              }else{
                ans.push_back(mn);
              }
            }
        }
        return ans;
    }
};