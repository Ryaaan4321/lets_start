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

    ll n;
    cin >> n;
    vli a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // check if n is odd;
    if (n & 1)
    {
        cout << 4 << endl;
        cout << 1 << " " << n - 1 << endl;
        cout << 1 << " " << n - 1 << endl;
        cout << n - 1 << " " << n << endl;
        cout << n - 1 << " " << n << endl;
    }
    else
    {
        // checking if n is even;
        cout << 2 << endl;
        cout << 1 << " " << n << endl;
        cout << 1 << " " << n << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
    return 0;
}