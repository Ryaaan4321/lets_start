#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
// And one day evrything got changed and he became his own companion;

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<vi> vvi;

void solve() {
    int a, b, n;
    cin >> a >> b >> n;
    
    vi x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        x[i] = min(x[i], a - 1);
    }
    
    ll ans = accumulate(x.begin(), x.end(), 0LL) + b;
    
    cout << ans << '\n';
}

int main(){
    int t;
    cin>>t;
    while(t-->0)
    {
        solve();
    }
    return 0;
}