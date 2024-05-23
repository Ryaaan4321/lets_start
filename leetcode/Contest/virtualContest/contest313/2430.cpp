// #include<bits/stdc++.h>
// #include<algorithm>
// #include<math.h>
// #include<string>

// using namespace std;

// class Solution {
// public:
//     int deleteString(string s) {
//         int n=s.size();
//         // string_view ss=s;
//         vector<int>dp(n+1,0);
//         for(int i=0;i<n;i++){
//             if(i>0 && dp[i]==0)continue;
//             dp[n]=max(dp[n],dp[i]+1);
//             for(int j=1;j<=(n-i)/2;j++){
//                 if(ss.substr(i,j)==ss.substr(i+j,j)){
//                     dp[i+j]=max(dp[i+j],dp[i]+1);
//                 }
//             }
//         }
//         return dp[n];
//     }
// };