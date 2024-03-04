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

bool find(vi a, int elm)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != elm)
            return false;
        return true;
    }
}

void solve()
{
    int n;
    cin >> n;
    vi pos, neg, a;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (x > 0)
            pos.push_back(x);
        else if (x < 0)
            neg.push_back(x);
        else
        {
            if (a.size() < 2)
                a.push_back(x);
        }
    }

    if (pos.size() > 2 || neg.size() > 2)
    {
        cout << "NO\n";return;
    }

    for (int i : pos)
    {
        a.push_back(i);
    }
    for (int i : neg)
    {
        a.push_back(i);
    }

    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = i + 1; j < a.size(); ++j)
        {
            for (int k = j + 1; k < a.size(); ++k)
            {
                int ok = 0;
                for (int z = 0; z < a.size(); ++z)
                {
                    if (a[i] + a[j] + a[k] == a[z])
                    {
                        ok = 1;
                    }
                }
                if (!ok)
                {
                    cout << "NO\n";
                    return;
                         
                }
            }
        }
    }
    cout << "YES\n";
    return;
}

int32_t main()
{
    w(t)
    {
        solve();
    }
    return 0;
}