#include <iostream>
#include <vector>
#include <algorithm> // for std::sort
#include <utility>
#include <bits/stdc++.h> // for std::pair, std::make_pair
/*And one day evrything got changed and he became his own companion;*/

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
Divide the test cases into the cases each and evry test case is a piece of the puzzle of that story so
there is a reason of that ;
still didnt make it yodha ho tum apni talwar uthao ar lag jao yudh mein rakt behna jayaj hai
try to write the brute force for the ist testcase or for the 2nd testcase and the question will always have a simple solution;
points - how does a% b works
If a is divisible by b, the result is 0.
If a is not divisible by b, the result is the remainder when a is divided by b.

*/

int n;
int a[1001];
int dp[1001][1001];
int dpCode(int left, int right)
{
    /*so by this form what we are intended to do is that we want to cut our rod into the as smaller pieces as much smaller we can
    and for this what we can do is  we can take two points left and right to solve this
    in the rod where the **left will be placed in the starting index and the **right will be placed in the n-1th index of the rod
    ** and at any point the left crosses the right so thats the end so return */
    if (left + 1 == right)
    {
        return 0;
    }
    /*the most formal situation*/
    if (dp[left][right] != -1)
    {
        return dp[left][right];
    }
    /*and hence we dont want to cut the rod from its starting points we want to cut from the left +1 and till the right -1 */
    int ans = 1e9;
    /*and after thaat the rod will be the a[right]-a[left] + the length of the left till that index point and the index point till the right*/
    for (int point = left + 1; point <= right - 1; ++point)
    {
        ans = min(ans, a[right] - a[left] + dpCode(left, point) + dpCode(point, right));
    }
    return dp[left][right] = ans;
    /*so basically this form of dp can be used to deal with the problems where we have to solve the question related to the 
    range or something and u should only consider to apply this form only when the constraints are low for the higher constraints this will give us tle*/
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << dpCode(0, n) << endl;
}

int32_t main()
{
    w(t)
    {
        solve();
    }
}