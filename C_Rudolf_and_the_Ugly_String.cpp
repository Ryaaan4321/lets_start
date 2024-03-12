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

bool check(vector<int>& counter){
    for(int &it:counter){
        if(it!=0){
            return false;
        }

    }
    return true;
}

void galat_Karam()
{
    int n;
    cin>>n;
    string s;cin>>s;
    vector<string>v;
    int cnt=0;
    for(int i=0;i<n-2;i++){
        string st=s.substr(i,3);
        if(st=="map" || st=="pie"){
            v.push_back(st);
        }
    }
   
    for(int i=0;i<n-4;i++){
        string x=s.substr(i,5);
        if(x=="mapie"){
            cnt++;
        }
    }

    if(v.empty()){
        cout<<0<<endl;
    }else{
        cout<<(v.size()-cnt)<<endl;
    }
    
}

void galat_Karam2(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    int ans=0;
    for(int i=0;i<n;i++){
        if(i+5<=n){
            string st=s.substr(i,5);
            if(st=="mapie"){
                ans++;
                i+=4;
                continue;
            }
        }
        if(i+3<=n){
            string ss=s.substr(i,3);
            if(ss=="pie" ||ss=="map"){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}

int32_t main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     w(t)
    {
    galat_Karam2();
    }

    // auto end = std::chrono::high_resolution_clock::now();
    // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "is it enough bitchh..?  " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}
