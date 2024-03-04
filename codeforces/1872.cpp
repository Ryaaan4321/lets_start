// #include <bits/stdc++.h>
// #include <algorithm>
// #include <iostream>
// #include <utility>
// // And one day evrything got changed and he became his own companion;

// using namespace std;

// typedef long long ll;
// typedef vector<int> vi;
// typedef vector<ll> vli;
// typedef vector<vi> vvi;
// const int inf = 1e18;

// void solve(){
// 	int n;
// 	cin >> n;
	
// 	vector<pair<int,int>> a(n);

	
	
	
// 	int l = 0,r = inf,ans = -1;
	
// 	while(l <= r){
// 		int m = (l + r) >> 1;
// 		bool ok = true;
		
// 		for(auto [d,s]:a){
// 			if(m < d)continue;
			
// 			if((m-d)*2 >= s){
// 				ok = false;
// 				break;
// 			}
			
// 		}
// 		if(ok){
// 			ans = m;
// 			l = m + 1;
// 		}
// 		else{
// 			r = m - 1;
// 		}
// 	}
	
// 	cout << ans << '\n';
// }
 
// int main(){
//     int t;
//     cin>>t;
//     while(t-->0){
//         solve();
//     }
// }