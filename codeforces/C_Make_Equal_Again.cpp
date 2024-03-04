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
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll MAX = 2e5 + 7;
typedef vector<pair<int, int>> vpi;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<char> vch;
typedef vector<vi> vvi;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ll add(ll a, ll b) { return ((a % mod) + (b % mod)) % mod; }
inline ll mul(ll a, ll b) { return ((a % mod) * (b % mod)) % mod; }
inline ll sub(ll a, ll b) { return ((a % mod) - (b % mod) + mod) % mod; }
inline ll power(ll x, ll n)
{
    if (!n)
    {
        return 1;
    }
    return (n & 1 ? mul(x, power(mul(x, x), n / 2)) : power(mul(x, x), n / 2));
}

inline int msb(ll n)
{
    for (int i = 33; i >= 0; i--)
    {
        if (n & (1ll << i))
        {
            return i;
        }
    }
}

inline ll nC2(ll n)
{
    return ((n * (n - 1)) / 2);
}
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

void galat_Karam()
{
    ll n;
    cin >> n;
    vl a(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    ll i = 0;
    while (i < n && a[i] == a[0])
    {
        i++;
    }
    // dbg(i);
    ll j = n - 1;
    while (j >= 0 && a[j] == a[n - 1])
    {
        j--;
    }
    // dbg(j);

    if (a[0] == a[n - 1])
    {
        cout << max(0ll, j - i + 1) << "\n";
    }
    else
    {
        cout << min(n - i, j + 1) << "\n";
    }
}
void galat_Karam2()
{
    ll n, answer = INT_MAX;
    cin >> n;
    vi a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    ll left = 0, leftCount = 0, right = n - 1, rightCount = 0;
    while (left < n && a[left] == a[0])
    {
        left++;
        leftCount++;
    }
    while (right >= 0 && a[right] == a[n - 1])
    {
        right--;
        rightCount++;
    }
    if (a[0] == a[n - 1])
    {
        cout << max(0ll, n - (leftCount + rightCount)) << "\n";
        /* code */
    }
    else
    {
        cout << min(n - leftCount, n - rightCount) << "\n";
    }
}
int32_t main()
{
    w(t)
    {
        galat_Karam();
    }
}