#include <iostream>
#include <vector>
#include <algorithm> 
#include <utility>
#include<math.h>
#include <bits/stdc++.h> 

//And one day evrything got changed and he became his own companion;/

using namespace std;

//debug macro starts here/

#ifndef DEBUG_TEMPLATE_CPP
#define DEBUG_TEMPLATE_CPP
#include <bits/stdc++.h>
// #define cerr cout
namespace __DEBUG_UTIL__ {
    using namespace std;
    void print(const char *x) { cerr << x; }
    void print(bool x) { cerr << (x ? "T" : "F"); }
    void print(char x) { cerr << '\'' << x << '\''; }
    void print(signed short int x) { cerr << x; }
    void print(unsigned short int x) { cerr << x; }
    void print(signed int x) { cerr << x; }
    void print(unsigned int x) { cerr << x; }
    void print(signed long int x) { cerr << x; }
    void print(unsigned long int x) { cerr << x; }
    void print(signed long long int x) { cerr << x; }
    void print(unsigned long long int x) { cerr << x; }
    void print(float x) { cerr << x; }
    void print(double x) { cerr << x; }
    void print(long double x) { cerr << x; }
    void print(string x) { cerr << '\"' << x << '\"'; }
    template <size_t N> void print(bitset<N> x) { cerr << x; }
    void print(vector<bool> v) { int f = 0; cerr << '{'; for (auto &&i : v) cerr << (f++ ? "," : "") << (i ? "T" : "F"); cerr << "}"; }
    template <typename T> void print(T &&x) { int f = 0; cerr << '{'; for (auto &&i : x) cerr << (f++ ? "," : ""), print(i); cerr << "}"; }
    template <typename T> void print(vector<vector<T>> mat) { int f = 0; cerr << "\n~~~~~\n"; for (auto &&i : mat) cerr << setw(2) << left << f++, print(i), cerr << "\n"; cerr << "~~~~~\n"; }
    template <typename T, size_t N, size_t M> void print(T (&mat)[N][M]) { int f = 0; cerr << "\n~~~~~\n"; for (auto &&i : mat) cerr << setw(2) << left << f++, print(i), cerr << "\n"; cerr << "~~~~~\n"; }
    template <typename F, typename S> void print(pair<F, S> x) { cerr << '('; print(x.first); cerr << ','; print(x.second); cerr << ')'; }
    template <typename T, size_t N> struct Tuple { static void printTuple(T t) { Tuple<T, N - 1>::printTuple(t); cerr << ",", print(get<N - 1>(t)); } };
    template <typename T> struct Tuple<T, 1> { static void printTuple(T t) { print(get<0>(t)); } };
    template <typename... Args> void print(tuple<Args...> t) { cerr << "("; Tuple<decltype(t), sizeof...(Args)>::printTuple(t); cerr << ")"; }
    template <typename... T> void print(priority_queue<T...> pq) { int f = 0; cerr << '{'; while (!pq.empty()) cerr << (f++ ? "," : ""), print(pq.top()), pq.pop(); cerr << "}"; }
    template <typename T> void print(stack<T> st) { int f = 0; cerr << '{'; while (!st.empty()) cerr << (f++ ? "," : ""), print(st.top()), st.pop(); cerr << "}"; }
    template <typename T> void print(queue<T> q) { int f = 0; cerr << '{'; while (!q.empty()) cerr << (f++ ? "," : ""), print(q.front()), q.pop(); cerr << "}"; }
    template <typename K, typename V> void print(map<K, V> m) { int f = 0; cerr << '{'; for (auto &&i : m) cerr << (f++ ? "," : ""), print(i); cerr << "}"; }
    void printer(const char *) {} /* Base Recursive */
    template <typename T, typename... V> void printer(const char *names, T &&head, V &&...tail) { int i = 0; for (size_t bracket = 0; names[i] != '\0' and (names[i] != ',' or bracket != 0); i++) if (names[i] == '(' or names[i] == '<' or names[i] == '{') bracket++; else if (names[i] == ')' or names[i] == '>' or names[i] == '}') bracket--; cerr.write(names, i) << " = "; print(head); if (sizeof...(tail)) cerr << " ||", printer(names + i + 1, tail...); else cerr << "]\n"; }
    void printerArr(const char *) {} /* Base Recursive */
    template <typename T, typename... V> void printerArr(const char *names, T arr[], size_t N, V... tail) { size_t ind = 0; for (; names[ind] and names[ind] != ','; ind++) cerr << names[ind]; for (ind++; names[ind] and names[ind] != ','; ind++); cerr << " = {"; for (size_t i = 0; i < N; i++) cerr << (i ? "," : ""), print(arr[i]); cerr << "}"; if (sizeof...(tail)) cerr << " ||", printerArr(names + ind + 1, tail...); else cerr << "]\n"; }
}

#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#endif

// debug macro ends here
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

 int distinctIntegers(int n) {
        set<int> st;
        queue<int> q;
        st.insert(n);
        q.push(n);
        while (!q.empty()) {
            int tope = q.front();
            for (int i = 1; i <= n; i++) {
                if (tope % i == 1) {
                    st.insert(i);
                    q.push(i);
                }
            }
            q.pop();
        }
        return st.size();
}
void galat_Karam()
{
   int n;cin>>n;
   int ans=distinctIntegers(n);
   cout<<ans<<endl;
};
//you gotta be almost insane to your craft - Sir mcgregor/

int32_t main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // w(t)
    // {
    galat_Karam();
    // }

    // auto end = std::chrono::high_resolution_clock::now();
    // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "is it enough bitchh..?  " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
    //mene time lagya koi na bola mujhe  laga reh to mene khud ko bola bas tu apna saga reh ar laga reh/
}