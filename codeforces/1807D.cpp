#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

using namespace std;
#define ll long long
#define int long long
#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define Long_MAX_VALUE 0x7fffffffffffffffL
#define Long_MIN_VALUE 0x8000000000000000L
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<vi> vvi;

void solve()
{
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i)
    {
        a[i] += a[i - 1];
    }
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        r--;
        int sum = a[n - 1];
        sum -= a[r] - (l == 0 ? 0 : a[l - 1]);
        sum += k * (r - l + 1);
        cout << (sum & 1 ? "YES\n" : "NO\n");
    }
}
signed main()
{
    int t;
    while (t-- > 0)
    {
        solve();
    }
}