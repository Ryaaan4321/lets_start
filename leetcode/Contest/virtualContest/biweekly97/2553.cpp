#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    stack<int> count(int n){
        stack<int>ans;
        while (n>0)
        {
            int val=n%10;
            ans.push(val);
            n/=10;
        }
        // reverse(ans./begin(),ans.end());
        return ans;
        
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>q;
        for(int i=0;i<nums.size();i++){
            stack<int>cnt=count(nums[i]);
            while(!cnt.empty()){
                q.push_back(cnt.top());
                cnt.pop();
            }
        }
        return q;
    }
};