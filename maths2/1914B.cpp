#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day everything got changed and he became his own companion
https://codeforces.com/contest/1914/problem/B */
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
const int MOD = 1e9 + 7;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n >> k;
        for (int i = n - k; i <= n; ++i)
        {
            cout << i << " ";
        }
        for (int i = n - k - 1; i > 0; --i)
        {
            cout << i << " ";
        }
        cout<<"\n";
    }
    return 0;
}