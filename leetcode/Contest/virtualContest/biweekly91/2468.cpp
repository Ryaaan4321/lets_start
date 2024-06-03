#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>


using  namespace std;

class Solution {
public:
    int distinctAverages(vector<int>& a) {
        sort(a.begin(),a.end());
        deque<int>dq;
        set<int>st;
        for(int i=0;i<a.size();i++){
            dq.push_back(a[i]);
        }
        while (dq.size())
        {
            int mn=dq.front();
            dq.pop_front();
            int mx=dq.back();
            dq.pop_back();
            int avg=(mx+mn)/2;
            st.insert(avg);

        }
        return st.size();
        
    }
};
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    Solution obj;
    int ans=obj.distinctAverages(a);
    cout<<" main walade debug "<<ans<<endl;
}