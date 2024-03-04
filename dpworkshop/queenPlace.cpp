#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

using namespace std;
#define ll long long
#define int long long
#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define Long_MAX_VALUE 0x7fffffffffffffffL
#define Long_MIN_VALUE 0x8000000000000000L
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<vi> vvi;

int n;
int queen[20];

bool check(int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        int prow = i;
        int pcol = queen[i];

        if (pcol == col || abs(col - pcol) == abs(row - prow))
        {
            return 0;
        }
    }
    return 1;
}

int rec(int level)
{
    if (level == n)
        return 1;
    /*compute*/
    int ans = 0;
    /*loop over all choices*/
    for (int col = 0; col < n; ++col)
    {
        /*check if the choice is valid */
        if (check(level, col))
        {
            /*place the queen*/
            queen[level] = col;
            /*explore the option*/
            ans += rec(level + 1);
            /*revert the placing queen*/
            queen[level] = -1;
        }
    }
    return ans;
}
void solve()
{
    cin >> n;
    memset(queen,-1,sizeof(queen));
    cout<<rec(0)<<endl;
};
signed main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
    return 0;
}