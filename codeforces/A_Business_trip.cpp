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
inline ll binary_exP(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >> 1;
        /* code */
    }
    return ans;
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

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
int k;
int a[12];
void galat_Karam()
{

    cin >> k;
    for (int i = 0; i < 12; i++)
        cin >> a[i];
    sort(a, a + 12);

    int cnt = 0;

    if (k == 0)
        cout << 0 << "\n";
    else
    {
        for (int i = 11; i >= 0; i--)
        {
            cnt += a[i];
            if (cnt >= k)
            {
                cout << 12 - i << "\n";
                break;
            }
        }
        if (cnt < k)
            cout << "-1\n";
    }
}

/*# include <cstdio>
# include <algorithm>
using namespace std;

int ar[13];

int main()
{
    int N;
    scanf("%d",&N);

    for(int i=0;i<12;i++)
        scanf("%d",ar+i);
    sort(ar,ar+12);

    int tot=0;
    for(int i=12;i>=0;i--)
    {
        tot+=ar[i];
        if(tot>=N)
        {
            printf("%d\n",12-i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
*/
int32_t main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    w(t)
    {
        galat_Karam();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "is it enough bitchh..?  " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}