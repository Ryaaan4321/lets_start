#include <iostream>
#include <vector>
#include <algorithm> 
#include <utility>
#include<math.h>
#include <bits/stdc++.h> 

//And one day evrything got changed and he became his own companion;/

using namespace std;

//debug macro starts here/
int recur_depth = 0;
#ifdef DEBUG
#define dbg(x) {++recur_depth; auto x_ = x; --recur_depth; cerr << string(recur_depth, '\t') << "\e[91m" << _func_ << ":" << _LINE_ << "\t" << #x << " = " << x_ << "\e[39m" << endl;}
#else
#define dbg(x)
#endif
template<typename Ostream, typename Cont> typename enable_if<is_same<Ostream, ostream>::value, Ostream &>::type operator<<(Ostream &os, const Cont &v) { os << "["; for (auto &x : v) { os << x << ", "; } return os << "]"; }
template<typename Ostream, typename... Ts> Ostream &operator<<(Ostream &os, const pair<Ts...> &p) { return os << "{" << p.first << ", " << p.second << "}"; }

#define ll long long
#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define Long_MAX_VALUE 0x7fffffffffffffffL
#define Long_MIN_VALUE 0x8000000000000000L
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define all(a) (a).begin(), (a).end()
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
inline ll power(ll x, ll n) { return (!n ? 1 : (n & 1 ? mul(x, power(mul(x, x), n / 2)) : power(mul(x, x), n / 2))); }
inline int msb(ll n) { for (int i = 33; i >= 0; i--) { if (n & (1ll << i)) return i; } }
inline ll nC2(ll n) { return (n * (n - 1)) / 2; }
inline ll binary_exp(ll a, ll b) { ll ans = 1; while (b) { if (b & 1) ans = ans * a % mod; a = a * a % mod; b >>= 1; } return ans; }

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

template<class T> void _print(T t){ cerr << t;}
template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
//time se badi koi investment ni phir fark ni padta ki pesha ky hai/



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
    int n;
    cin>>n;
};
//you gotta be almost insane to your craft - Sir mcgregor/

int32_t main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    w(t)
    {
    galat_Karam();
    }

    // auto end = std::chrono::high_resolution_clock::now();
    // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "is it enough bitchh..?  " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
    //mene time lagya koi na bola mujhe  laga reh to mene khud ko bola bas tu apna saga reh ar laga reh/
}