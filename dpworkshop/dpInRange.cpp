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

int n;
int tt; /*target*/
int x[101];
int dp[105][10100];
/*recursive code*/
int rec(int level, int taken)
{
    /*pruning*/
    if (taken > tt)
        return 0;
    /*base case*/
    if (level == n + 1)
    {
        if (tt == taken)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    /*compute*/
    int ans = 0;

    if (rec(level + 1, taken) == 1)
    {
        ans = 1;
    }
    else if (rec(level + 1, taken + x[level]))
    {
        ans = 1;
    }
    return ans;
}
/*dp code*/
int dpCode(int level, int taken)
{
    /*pruning*/
    if (taken > tt)
    {
        return 0;
    }
    /*base caase*/
    if (level == n + 1)
    {
        if (tt == taken)
            return 1;
        else
            return 0;
    }
    /* cache check*/
    if (dp[level][taken] != -1)
    {
        return dp[level][taken];
    }

    int ans = 0;
    if (dpCode(level + 1, taken) == 1)
    {
        ans = 1;
    }
    else if (dpCode(level + 1, taken + x[level]))
    {
        ans = 1;
    }
    return dp[level][taken] = ans;
}
/*range query
 There are N items x1,x2 , x3.......xn Find a subset of the items exist that sums up to the
 Target -> T

 Example -[1 , 2 , 5 , 9]
 we need to find the subset for the T=3,T=4,T=16;

 n<100;
 xi<=10^4;
*/
int dppCodee(int level, int leftSum)
{
    if (leftSum < 0)
        return 0;

    /*base case*/
    if (level == n + 1)
    {
        if (leftSum == 0)
        {
            return 0;
        }
        else
        {
            return 0;
        }
    }
    /*cache check*/

    if (dp[level][leftSum] != -1)
        return dp[level][leftSum];

    /*compute*/
    int ans = 0;

    if (dppCodee(level + 1, leftSum) == 1)
    {
        ans = 1;
    }
    else if (dppCodee(level + 1, leftSum - x[level]))
    {
        ans = 1;
    }
    return dp[level][leftSum] = ans;
}
// void printset(int level, int left)
// {
//     /*vase caase*/
//     if (level == n + 1)/*if we have traversed in whole array then retun whatever value we have*/
//         return;

//     /*correct tranistion*/
//     if (dppCodee(level + 1, left) == 1)
//     {
//         printset(level + 1, left);
//     }
//     else if (dppCodee(level + 1, left - x[level]))
//     {
//         cout << x[level] << "";
//         printset(dppCodee(dppCodee+1 ,left-x[level]));
//     }
// }

// void solve()
// {
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; ++i)
//     {
//         cin >> x[i];
//     }
//     memset(dp, -1, sizeof(dp));

//     cin >> tt;
//     memset(dp, -1, sizeof(dppCodee)); // order of states O(#S)+O(DP);
//     if (dppCodee(1, tt))
//     {
//         printset(1, tt);
//     }
// }

// int32_t main()
// {
//     w(t)
//     {
//         solve();
//     }
//     return 0;
// }