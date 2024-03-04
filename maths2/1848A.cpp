#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
// And one day evrything got changed and he became his own companion;

using namespace std;
using str = std::string;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<vi> vvi;

void solve(vector<vector<int>> adj, vector<vector<int>> adj1)
{
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int x, y;
        cin >> x >> y;
        str ans = "YES\n";
        for (int i = 0; i < k; ++i)
        {
            int xx, yy;
            cin >> xx >> yy;
            if ((x + y) % 2 == (xx + yy) % 2)
            {
                ans = "NO\n";
            }
        }
        cout << ans;
        /* code */
    }
}