#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

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

int func(int n)
{
    if (n == 0)
        return 1;
    return n * func(n - 1);
};
int fibonacci(int n){
    if(n==0 || n==1)return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}
signed main()
{
    int n;
    cin >> n;
    int ans = fibonacci(n);
    cout << ans << endl;
    return 0;
}