#include <iostream>
#include <vector>
#include <algorithm> // for std::sort
#include <utility>
#include <bits/stdc++.h> // for std::pair, std::make_pair
/*And one day evrything got changed and he became his own companion;*/

using namespace std;
#define int long long
#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define Long_MAX_VALUE 0x7fffffffffffffffL
#define Long_MIN_VALUE 0x8000000000000000L
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
typedef vector<pair<int, int>> vpi;
typedef vector<int> vi;
typedef vector<int> vli;
typedef vector<vi> vvi;
/*
----------------------------------------------------------------------------- THINGS TO REMEMBER  ----------------------------------------------------------------
--------------------- TLE : INFINITE LOOP  ,OR CHECK THE CONSTRAINTS AND THE LOOPS--------------------------------------------------------------------------------
--------------------- MLE :  CHCK FOR THE SIZE OF THE MEMORY------------------------------------------------------------------------------------------------------
--------------------- RE : POP THE EMPTY ARRAY OR THE STACK ,QUEUE OR THE INDEX BOUNDS----------------------------------------------------------------------------
*/
signed main()
{
    const int N = 1e5 + 5;
    const int mod = 1e9 + 7;
    vi fact(N);
    fact[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
    }
    int t;
    cin>> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int ans = n * (n - 1);
        ans %= mod;
        ans = (ans * fact[n]) % mod;
        cout << ans << endl;

        /* code */
    }
    return 0;
}