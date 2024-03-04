#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
// And one day evrything got changed and he became his own companion;

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<vi> vvi;

void solve()
{
    string s;
    cin >> s;

    int cur = 1, ans = 0;

    for (int i = 0; i < 4; i++)
    {
        int now = s[i] - '0';
        if (now == 0)
            now = 10;

        while (cur < now)
            cur++, ans++;
        while (cur > now)
            cur--, ans++;
    }

    cout << ans + 4 << "\n";
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
}