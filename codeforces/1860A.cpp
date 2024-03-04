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
    while (t-- > 0)
    {
        string s;
        cin >> s;
        int n = s.size();
        string a, b;
        for (int i = 0; i < 2 * n; ++i)
        {
            a += "()"[i & 1];
            b += ")("[i < n];
        }
        if (a.find(s) == string::npos)
        {
            cout << "YES\n"
                 << a << '\n';
        }
        else if (b.find(s) == string::npos)
        {
            cout << "YES\n"
                 << b << '\n';
        }
        else
        {
            cout << "NO\n";
        }
        /* code */
    }
}