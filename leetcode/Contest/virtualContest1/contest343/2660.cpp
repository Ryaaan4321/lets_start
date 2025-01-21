#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int isWinner(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int sc1=a[0];int sc2=b[0];
        for(int i=1;i<n;i++){
            sc1+=a[i];sc2+=b[i];
            if(i==1){
                if(a[0]==10)sc1+=a[i];
                if(b[0]==10)sc2+=b[i];
            }else{
                if((a[i-1]==10)|| a[i-2]==10){
                    sc1+=a[i];
                }
                if((b[i-1]==10)||b[i-2]==10){
                    sc2+=b[i];
                }
            }
        }
        return sc1 > sc2 ? 1 : (sc2 > sc1 ? 2 : 0);
    }
};
// int main(){
//     int n;cin>>n;
//     int m;cin>>m;
//     vector<int>a(n);
//     vector<int>b(n);
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//         cin>>b[i];
//     }
//     Solution sol;
//     int ans=sol.isWinner(a,b);
//     cout<<ans <<"="<<"ans"<<endl;
// }