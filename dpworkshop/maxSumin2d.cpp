#include <iostream>
#include <vector>
#include <algorithm> // for std::sort
#include <utility>
#include <bits/stdc++.h> // for std::pair, std::make_pair
/*And one day evrything got changed and he became his own companion;*/

using namespace std;

/*debug macro starts here*/
int recur_depth = 0;
#ifdef DEBUG /*aryan ka laptop*/
#define dbg(x)                                                                                                                         \
    {                                                                                                                                  \
        ++recur_depth;                                                                                                                 \
        auto x_ = x;                                                                                                                   \
        --recur_depth;                                                                                                                 \
        cerr << string(recur_depth, '\t') << "\e[91m" << __func__ << ":" << __LINE__ << "\t" << #x << " = " << x_ << "\e[39m" << endl; \
    }
#else
#define dbg(x)
#endif
template <typename Ostream, typename Cont>
typename enable_if<is_same<Ostream, ostream>::value, Ostream &>::type operator<<(Ostream &os, const Cont &v)
{
    os << "[";
    for (auto &x : v)
    {
        os << x << ", ";
    }
    return os << "]";
}
template <typename Ostream, typename... Ts>
Ostream &operator<<(Ostream &os, const pair<Ts...> &p)
{
    return os << "{" << p.first << ", " << p.second << "}";
}
/*debug macro ends here*/
#define ll long long
#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define Long_MAX_VALUE 0x7fffffffffffffffL
#define Long_MIN_VALUE 0x8000000000000000L
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)

typedef vector<pair<int, int>> vpi;
typedef vector<int> vi;
typedef vector<int> vli;
typedef vector<vi> vvi;
/*
----------------------------------------------- THINGS TO REMEMBER ----------------------------------------------------------------
--------------------- TLE : INFINITE LOOP  ,OR CHECK THE CONSTRAINTS AND THE LOOPS--------------------------------------------------------------------------------
--------------------- MLE :  CHCK FOR THE SIZE OF THE MEMORY------------------------------------------------------------------------------------------------------
--------------------- RE : POPING THE EMPTY ARRAY OR THE STACK ,QUEUE OR THE INDEX BOUNDS----------------------------------------------------------------------------
*/
int dp[1001][1001];
int a[1001][1001];
int n, m;
bool done[1001][1001];

int rec(int row, int col)
{
    /* pruning */
    if (row < 0 || col < 0)
    {
        return -1e9;
    }
    /* base case */
    if (row == 0 && col == 0)
    {
        return 0; // Fix this line
    }
    if (done[row][col])
    {
        return dp[row][col];
    }
    int ans = -1e9;
    if (row != 0)
    {
        ans = max(ans, rec(row - 1, col) + a[row][col]);
    }
    if (col != 0)
    {
        ans = max(ans, rec(row, col - 1) + a[row][col]);
    }
    if (row + 1 != 0 && col + 1 != 0)
    {
        ans = max(ans, rec(row + 1, col + 1) + a[row][col]);
    }
    done[row][col] = 1;
    return dp[row][col] = ans;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
            done[i][j] = 0;
        }
    }
    int result = rec(n - 1, m - 1); // Call the rec function with the bottom-right corner
    cout << result << endl;
}

int32_t main()
{
    w(t)
    {
        solve();
    }
    return 0;
}