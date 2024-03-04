#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

using namespace std;

typedef long long ll;
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
        cin >> n >> k;
        vi a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i]--;
        }
        int bad = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] % k != i % k)
            {
                bad++;
            }
        }
        if (bad == 0)
            cout << 0 << '\n';
        else if (bad == 2)
            cout << 1 << '\n';
        else
            cout << -1 << '\n';
    }
    return 0;
}