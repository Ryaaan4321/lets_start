#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;
class Solution {
public:
    int fucc(int n){
        int sm=0;
        while(n!=0){
            int rem=n%10;
            sm+=rem;
            n=n/10;
        }
        return sm;
    }
    int minElement(vector<int>& nums) {
        vector<int>a;
        for(int i=0;i<nums.size();i++){
           int sm=fucc(nums[i]);
           a.push_back(sm);
        }
        return *min_element(begin(a),end(a));
    }
};