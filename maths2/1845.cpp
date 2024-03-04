#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
// And one day evrything got changed and he became his own companion;

using namespace std;
using str = std::string;

#define x first
#define y second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<vi> vvi;
typedef pair<int, int> pt;



int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
       ll x1, y1, x2 , y2 , x3 , y3,ab=0, ac=0,bc=0;
       cin>>x1 >> y1>>x2>>y2>>x3>>y3;
       bc=abs(x2-x3)+abs(y2-y3)-1+2;
       ab=abs(x2-x1)+abs(y2-y1)-1+2;
       ac=abs(x1-x3)+abs(y1-y3)-1+2;

       if(ac==ab+bc){
        cout<<1<<endl;
       }else{
        ll r = ab+ac-bc;
        ll p =(r-1)/2;
        cout<<p+1<<endl;
       }
    }

    return 0;
}