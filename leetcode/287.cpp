#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       unordered_map<int,int>mp;
       for(int it:nums){
          mp[it]++;
       }
       for(auto it:mp){
        if(it.second>1){
            return it.first;
        }
       }
       return -1;
        
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    Solution obj;
    int ans=obj.findDuplicate(a);
    cout<<ans<<endl;

}
