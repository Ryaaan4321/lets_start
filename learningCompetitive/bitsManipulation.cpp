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
void printBinary(int num)
{
    for (int i = 10; i >= 0; --i)
    {
        cout << ((num >> i) & 1);
    }
}

int32_t main()
{
    int a ;
    int n ;
    cin>> n;
    cin>>a;
    for (int i = 0; i < n; ++i)
    {
        if (a & (1 << i))
        {
            // cout << "setBit"
            //      << " : index " << i << "\n"; // to check if the bit is set or not
        }
        else
        {
            // cout << "notsetBit"
            //      << " : index " << i << "\n";
        }
    }
    // printBinary(a);
    // cout << "\n";
    // printBinary(a | (1 << 4)); // setting the bit in the particular postition;
    // cout << "\n";
    // printBinary(a & ~(1 << 0)); // unsetting the bit in the particular position;
    // cout << "\n";

    // cout << __builtin_popcount(a) << endl; // to check how many bits are sit of the n;

    int cnt = 0;
    for (int i = a; i >= 0; --i)
    {
        if (a & (1 << i))
        {
            cnt++;
            cout<<(a&(1<<i))<<"\n";
        }
        
    }
    // cout << cnt << "\n";//this will also check that the bit in the particular bit is set or not;

    return 0;
}