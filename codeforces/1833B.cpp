#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<vi> vvi;

void  solve(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>>a(n);
    vector<int>b(n), ans(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    for(auto &i : b) cin >> i;
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++){
        ans[a[i].second] = b[i];
    }
    for(auto &i : ans) cout << i << ' ';
    cout << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
}