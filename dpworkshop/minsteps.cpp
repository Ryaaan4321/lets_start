#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

using namespace std;
#define ll long long
#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define Long_MAX_VALUE 0x7fffffffffffffffL
#define Long_MIN_VALUE 0x8000000000000000L
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<vi> vvi;

int n;
int tt[1001];
int s[1001];
int x, k;

int dp[101][101][101];
/*so dp is not a recursion bt a optimized recursion
 or you can say not a motherfucker bt a optimized & hollistic motherfucker
/*dp code for this problem*/
int recdp(int level, int time_taken, int item_taken)
{
    if (level == n)
        return 0;

    if (dp[level][time_taken][item_taken] != -1)
    {
        return dp[level][time_taken][item_taken];
    }

    int ans = recdp(level + 1, time_taken, item_taken);

    if (time_taken + level <= x && item_taken + 1 <= k)
    {
        ans = min(ans, level + recdp(level + 1, time_taken + level, item_taken));
    }
    return dp[level][time_taken][item_taken] = ans;
}

int rec(int level)
{
    if (level > n)
    {
        return 0;
    }
    if (level == n)
    {
        return 1;
    }
    int ans = 0;
    for (int step = 1; step <= 3; ++step)
    {
        if (level + step <= n)
        {
            int ways = rec(level + step);
            ans += ways;
        }
    }
    return ans;
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> x >> k;
    cout << recdp(2, 1, 1) << endl;
}

int32_t main()
{
    int testCases;
    cin >> testCases;
    while (testCases-- > 0)
    {
        solve();
    }
    return 0;
}