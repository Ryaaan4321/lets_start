#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int c=count(begin(nums),end(nums),1);
        if(c!=0){
           return n-c;
        }
        int  res=1e7;
        for(int i=0;i<n;i++){
            int g=nums[i];
            for(int j=i+1;j<n;j++){
                g=__gcd(g,nums[j]);
                if(g==1){
                    res=min(res,j-i+(n-1));
                    break;
                }
            }
        }
        return res==1e7?-1:res;
    }
};