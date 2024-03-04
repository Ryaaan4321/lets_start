#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
//And one day everything got changed and he became his own companion
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


int32_t main()
{
    int t;
    cin>>t;
    while(t-->0){
        ll a ;
        ll b;
        cin >> a ;
        cin >> b;

        while(a!=0 || b!=0)
        {
            swap(a,b);
            a--;
            swap(b,a);
            b--;
            swap(a,b);
            
        }
    }

    return 0;
}