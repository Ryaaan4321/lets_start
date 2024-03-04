#include <iostream>
#include <vector>
#include <algorithm> // for std::sort
#include <utility>
#include <bits/stdc++.h> // for std::pair, std::make_pair
/*And one day everything got changed and he became his own companion;*/

using namespace std;

/*debug macro starts here*/
int recur_depth = 0;
#ifdef DEBUG /*aryan  tu kr rha hai ar tu krta rehhhhh */
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
typedef vector<long long> vl;
typedef vector<char> vch;
typedef vector<vi> vvi;
/*
----------------------------------------------- THINGS TO REMEMBER ----------------------------------------------------------------
--------------------- TLE : INFINITE LOOP  ,OR CHECK THE CONSTRAINTS AND THE LOOPS--------------------------------------------------------------------------------
--------------------- MLE :  CHCK FOR THE SIZE OF THE MEMORY------------------------------------------------------------------------------------------------------
--------------------- RE : POPING THE EMPTY ARRAY OR THE STACK ,QUEUE OR THE INDEX BOUNDS----------------------------------------------------------------------------
Read and try to understand each and every test case the existence of
everything == 1 not == 0 ( ^_^ )
Divide the test cases into the cases each and every test case is a piece of the puzzle of that story so
there is a reason of that ;
still didnt make it yodha ho tum apni talwar uthao ar lag jao yudh mein rakt behna jayaj hai
try to write the brute force for the ist testcase or for the 2nd testcase and the question will always have a simple solution;
points - how does a% b works
If a is divisible by b, the result is 0.
If a is not divisible by b, the result is the remainder when a is divided by b.

*/

int n, m, x;
string a;
string b;
string c;
int dp[1001][1001];
int dp2[1001][1001][1001];
/*form 3 of the dp which can be used when we are trying to compare the certain elements with the another elemnets on that case
this can be used and can be benficial to optimise  our code and time complexity lets talk a shit about this code 
so here in this code we are trying to get the longest length of the common subsequence in between the 3 strings so what can we do
can take three pointers and can check in each case that are they equal or not if they are equal than we will mover further will all that 
string index elements and if not then we will move forward accordingly 
one step at a time  thats it for this i am feeling lazy i cnt type more so thats it for this tutorial
happy coding fuck your coding bitches i m going to sleep you to go get some good sleep 
 
*/

int dpCode1(int i, int j, int k)
{
    if (i >= n || j >= m || k >= x)
    {
        return 0;
    }
    if (dp2[i][j][k] != -1)
    {
        return 0;
    }
    int ans = 0;
    ans = max(ans, dpCode1(i + 1, j, k));
    ans = max(ans, dpCode1(i, j + 1, k));
    ans = max(ans, dpCode1(i, j, k + 1));

    if (a[i] == b[j] && b[j] == c[k])
    {
        ans = max(ans, 1 + dpCode1(i + 1, j + 1, k + 1));
    }
    return dp2[i][j][k] = ans;
}
int dpCode(int i, int j)
{
    if (i >= n || j >= m)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = 0;
    ans = max(ans, dpCode(i + 1, j));
    ans = max(ans, dpCode(i, j + 1));
    if (a[i] == b[j]) // Corrected comparison here
    {
        ans = max(ans, 1 + dpCode(i + 1, j + 1));
    }
    return dp[i][j] = ans;
}

void solve()
{
    cin >> n;
    cin >> m;
    cin >> x;
    cin >> a;
    cin >> b;
    cin >> c;

    memset(dp, -1, sizeof(dp));
    cout << dpCode(0, 0) << endl;
}

int main()
{
    w(t)
    {
        solve();
    }
}
