#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

using namespace std;
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        int sum1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
                sum = 0;
            }
            else if (nums[i] > 0)
            {
                sum1 += nums[i];
            }
        }
        return sum - sum1;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    Solution obj;
    int ans=obj.firstMissingPositive(a);
    cout<<ans<<endl;
}