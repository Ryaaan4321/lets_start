#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;

#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define Long_MAX_VALUE 0x7fffffffffffffffL
#define Long_MIN_VALUE 0x8000000000000000L

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<vi> vvi;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;
        ll mnA = *min_element(a.begin(), a.end());
        ll sA = accumulate(a.begin(), a.end(), 0LL);
        ll mnB = *min_element(b.begin(), b.end());
        ll sB = accumulate(b.begin(), b.end(), 0LL);
        ll ans = min(mnA * n + sB, mnB * n + sA);
        cout << ans << '\n';
    }
}
