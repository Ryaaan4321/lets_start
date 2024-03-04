#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    
    int solve(){

    }
    int maxOperations(vector<int> &nums)
    {
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    Solution obj;
    int ans=obj.maxOperations(a);
    cout<<ans<<endl;
}