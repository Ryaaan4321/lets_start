#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans=0;
        deque<int>dq;
        for(int i=0;i<(int)nums.size();i++){
            dq.push_back(nums[i]);
        }
        string str="";
        while(!dq.empty()){
            if(dq.size()==1){
                long long f=dq.front();
                dq.pop_front();
                str=to_string(f);
                ans+=stoll(str);
            }else{
            int f=dq.front();
            dq.pop_front();
            int b=dq.back();
            dq.pop_back();
            str=to_string(f)+to_string(b);
            ans+=(long long)stoll(str);
        }
        }
        return ans;

    }
};