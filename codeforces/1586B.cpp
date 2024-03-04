#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/* And one day evrything got changed and he became his own companion; */ 
/*    problem statement
https://codeforces.com/problemset/problem/1583/B
*/

using namespace std;
using str = std::string;

#define x first
#define y second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<vi> vvi;
typedef pair<int, int> pt;

int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n,m;
        cin>> n>>m;
        unordered_set<int> map;
        for(int i=0;i<m;++i){
            int a , b, c;
            cin>>a >> b>>c;
            map.insert(b);


        }
        int middle=-1;
        for(int i=1;i<=n;i++){
            if(map.find(i)==map.end()){
                middle=i;
                break;
            }

        }
        for(int k=1;k<=n;++k){
            if(k==middle){
                continue;
                
            }
            cout<<k<<" "<<middle<<"\n";
        }
    }
}