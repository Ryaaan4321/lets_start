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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        vi A(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> A[i];
        }

        int mn = *min_element(A.begin(), A.end());
        int mx = *max_element(A.begin(), A.end());

        int cmn = 0, cmx = 0;
        for (auto x : A)
        {
            if (x == mn)
                cmn++;
            else if (x == mx)
                cmx++;
        }

        if (mn == mx)
        {
            cout << ((int)n * (int)(n - 1)) << "\n";
        }
        else
        {
            cout << 2ll * (int)cmn * (int)cmx << "\n";
        }
    }
    return 0;
}