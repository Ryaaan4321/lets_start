#include <iostream>
#include <vector>
#include <algorithm> // for std::sort
#include <utility>
#include <bits/stdc++.h> // for std::pair, std::make_pair
/*And one day evrything got changed and he became his own companion;*/

using namespace std;
#define ll long long
#define int long long
#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define Long_MAX_VALUE 0x7fffffffffffffffL
#define Long_MIN_VALUE 0x8000000000000000L
typedef vector<pair<int, int>> vpi;
typedef vector<int> vi;
typedef vector<long long> vli;
typedef vector<vi> vvi;

// void solve()
// {
//     int x[4], y[4];
//     for (int i = 0; i < 4; ++i)
//         cin >> x[i] >> y[i];
//     int mx = *max_element(x, x + 4);
//     int mn = *min_element(x, x + 4);

//     cout << (mx - mn) * (mx - mn) << "\n";
// }

signed main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {

        int x[4], y[4];
        for (int i = 0; i < 4; ++i)
            cin >> x[i] >> y[i];
        int mx = *max_element(x, x + 4);
        int mn = *min_element(x, x + 4);

        cout << (mx - mn) * (mx - mn) << "\n";
    }
    return 0;
}