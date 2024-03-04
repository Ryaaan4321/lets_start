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
        ll l, r;
        cin >> l >> r;
        map<ll, ll> ans;
        for (ll i = l; i <= min(r, l + 90); ++i)
        {
            ll now = i;
            ll mx = -1ll, mn = Integer_MIN_VALUE;

            while (now)
            {
                mx = max(mx, now % 10);
                mn = min(mn, now % 10);

                now /= 10;
            }
            ans[mx - mn] = i;
        }
        for (ll i = 9; i >= 0; --i)
        {
            if (ans[i])
            {
                cout << ans[i] << endl;
                break;
            }
        }
    }
    return 0;
}