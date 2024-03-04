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
int dp[10010];
int n;
int a[10010];
int dpL[10010];
int dpLast[10010];

int dpp(int level)
{
    /*pruning or base check*/

    if (level < 0)
        return 0;
    /*cache check*/
    if (dp[level] != -1)
        return dp[level];

    int ans = 1;
    /* computation*/
    for (int prev_taken = 0; prev_taken < level; ++prev_taken)
    {
        if (a[prev_taken] < a[level])
        {
            ans = max(ans, 1 + dpp(prev_taken));
        }
    }
    
    return dp[level] = ans;
}

void solve()
{
    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    
    memset(dp, -1, sizeof(dp));
    
    int result = 0;
    
    for (int i = 0; i < n; ++i)
    {
        result = max(result, dpp(i));
    }

    cout << result << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}