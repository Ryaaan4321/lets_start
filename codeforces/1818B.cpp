#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<vi> vvi;

void solve(){
    int n;
    cin>>n;
    if(n==1){
        cout<<1<<"\n";
    }
    else if(n%2){
        cout<<-1<<"\n";
    }else{
        int a[n];
        iota(a,a+n,1);
        for(int i=0;i<n;i+=2){
            swap(a[i+1],a[i]);
        }
        for(auto it:a){
            cout<<it<<' ';
        }
        cout<<"\n";
    }
}
int main()
{
    int t;
    while (t-- > 0)
    {
        solve();
        /* code */
    }
}