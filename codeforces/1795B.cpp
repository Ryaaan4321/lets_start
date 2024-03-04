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

signed main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n;
        cin >> k;

        int L = 0, R = 55;
        while (n-- > 0)
        {
            int l, r;
            cin >> l;
            cin >> r;
            if (l <= k && k <= r)
            {
                L = max(L, l), R = min(R, r);
            }
        }
        cout << (L == R ? "YES\n" : "NO\n");
        /* code */
    }
}