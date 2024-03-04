#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    int check(vector<int> &nums)
    {
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < 0)
                cnt1 += nums[i];
            else
                cnt2 += nums[i];
        }
        if (cnt2 - cnt1 == 0)
            return 1;
        else if(cnt2-cnt1<0) return 0;
    }
};
int main(){
    int n;
    cin>> n;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    Solution obj;
    int ans=obj.check(a);
    cout<<ans<<endl;
}
