// #include <bits/stdc++.h>
// #include <algorithm>
// #include <iostream>
// // And one day everything got changed and he became his own companion
// using namespace std;
// #define ll long long
// #define int long long
// #define Integer_MAX_VALUE 0x7fffffff
// #define Integer_MIN_VALUE 0x80000000
// #define Long_MAX_VALUE 0x7fffffffffffffffL
// #define Long_MIN_VALUE 0x8000000000000000L
// typedef vector<int> vi;
// typedef vector<ll> vli;
// typedef vector<vi> vvi;

// void solve(){
//     int n;
//     cin >> n;

//     int l = 1;
//     int r = 1e9;
//     int s = 0;
    
//     vector<int> neq;

//     for (int i = 0; i < n; i++){
//         int a, x;
//         cin >> a >> x;

//         if (a == 1)
//             l = max(l, x);
//         if (a == 2)
//             r = min(r, x);
//         if (a == 3)
//             neq.push_back(x);
//     }
//     for (int x : neq)
//         if (x >= l and x <= r)
//             s++;
    
//     cout<<max(r - l + 1 - s, 0)<<"\n";
// }

// int main(){
//     ios_base::sync_with_stdio(0); cin.tie(0); 
//     int tc; 
//     cin >> tc;

//     while (tc--)
//         solve();
// }