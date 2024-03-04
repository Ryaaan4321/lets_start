#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/* And one day evrything got changed and he became his own companion; */
/*    problem statement
https://codeforces.com/problemset/problem/1583/B
*/

using namespace std;
using str = std::string;

#define x first
#define y second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<vi> vvi;
typedef pair<int, int> pt;

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int orda = 'a';
        int n;
        cin >> n;

        vector<int> cnt(26, 0);
        for (int i = 0; i < n; i++)
        {
            char c;
            cin >> c;
            cnt[c - orda]++;
        }

        int mx = 0;
        for (int i = 0; i < 26; i++)
        {
            mx = max(mx, cnt[i]);
        }

        cout << max(n % 2, 2 * mx - n) << endl;
    }

    return 0;
}