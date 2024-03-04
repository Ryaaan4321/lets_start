#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

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
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans=1;
        int cnt=1;

        for (int i = 1; i < n; ++i)
        {
            if (s[i] != s[i - 1]) cnt = 1;
            else cnt++;
            ans = max(ans, cnt);
        }

        cout << ans + 1 << endl;

        /* code */
    }
}