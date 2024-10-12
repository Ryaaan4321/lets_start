#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();int zcnt=0;
        int left=0;int right=0;
        int mlen=0;
        while(right<n){
            if(nums[right]==0){
                zcnt++;
            }
            if(zcnt<=k){
                mlen=max(mlen,right-left+1);
            }else if(zcnt>k){
                while(zcnt>k){
                    if(nums[left]==0){
                        zcnt--;
                    }
                    left++;
                }
            }
            right++;
        }
        return mlen;
    }
};
int main(){
    int n;cin>>n;
    vector<int>a(n);
    int k;cin>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
     Solution sol;
    // Get the result by calling the method
    int res = sol.longestOnes(a, k);

    // Print the result
    cout << res << endl;

    return 0;
};