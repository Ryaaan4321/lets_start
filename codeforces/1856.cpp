#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
// And one day evrything got changed and he became his own companion;

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<vi> vvi;

int main()
{
    int t;
    cin>>t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        vi a(n);
        ll sum = 0;
        int cnt1=0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
          
        }
        for(int x:a){
            sum+=x;
            if(x==1)cnt1++;
        }
        // if (a.size() <= 2)
        //     cout << "NO" << endl;
        if (sum >=cnt1 + n && n>1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}