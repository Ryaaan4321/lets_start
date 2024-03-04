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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            a[i]++;
        }
    }
    for (int i = 1; i < n; ++i)
    {
        if (a[i] % a[i - 1] == 0)
        {
            a[i]++;
        }
    }
    for (auto val : a)
        cout << val << " " << endl;

    return;
}

signed main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
        /* code */
    }
    return 0;
}