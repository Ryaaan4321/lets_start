#include <iostream>
#include <vector>
#include <algorithm> // for std::sort
#include <utility>
#include <bits/stdc++.h> // for std::pair, std::make_pair
/*And one day evrything got changed and he became his own companion;*/

using namespace std;
#define ll long long
#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define Long_MAX_VALUE 0x7fffffffffffffffL
#define Long_MIN_VALUE 0x8000000000000000L
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
typedef vector<pair<int, int>> vpi;
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<vi> vvi;
/*
----------------------------------------------------------------------------- THINGS TO REMEMBER  ----------------------------------------------------------------
--------------------- TLE : INFINITE LOOP  ,OR CHECK THE CONSTRAINTS AND THE LOOPS--------------------------------------------------------------------------------
--------------------- MLE :  CHCK FOR THE SIZE OF THE MEMORY------------------------------------------------------------------------------------------------------
--------------------- RE : POP THE EMPTY ARRAY OR THE STACK ,QUEUE OR THE INDEX BOUNDS----------------------------------------------------------------------------
*/

void solve()
{
    ll n, f, a, b;
    cin >> n >> f >> a >> b;
    vli arr(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    ll cur = f;
    ll time = 0;
    for (int i = 0; i < n; i++)
    {
        ll delay = arr[i] - time;
        ll mincon = min(delay * a, b);
        cur -= mincon;
        if (cur <= 0)
        {
            no;
            return;
        }
        time = arr[i];
    }
    yes;
}
int main()
{
    int t;
    cin>>t;
    while (t-- > 0)
    {
        solve();
    }
}
