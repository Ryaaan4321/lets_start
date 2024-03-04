#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
// And one day evrything got changed and he became his own companion;

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<vi> vvi;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k, x;
        cin >> n >> k >> x;

        int mi = k * (k + 1) / 2;
        int mx = n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2;

        if (x >= mi && x <= mx)
            cout << "YES\n";
        else
            cout << "No\n";
    }
    return 0;
}

