#include <iostream>
#include <vector>
#include <algorithm> // for std::sort
#include <utility>
#include <bits/stdc++.h> // for std::pair, std::make_pair
/*And one day evrything got changed and he became his own companion;*/

using namespace std;
#define int long long
#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define Long_MAX_VALUE 0x7fffffffffffffffL
#define Long_MIN_VALUE 0x8000000000000000L
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
typedef vector<pair<int, int>> vpi;
typedef vector<int> vi;
typedef vector<int> vli;
typedef vector<vi> vvi;
/*
----------------------------------------------------------------------------- THINGS TO REMEMBER  ----------------------------------------------------------------
--------------------- TLE : INFINITE LOOP  ,OR CHECK THE CONSTRAINTS AND THE LOOPS--------------------------------------------------------------------------------
--------------------- MLE :  CHCK FOR THE SIZE OF THE MEMORY------------------------------------------------------------------------------------------------------
--------------------- RE : POP THE EMPTY ARRAY OR THE STACK ,QUEUE OR THE INDEX BOUNDS----------------------------------------------------------------------------
*/

signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
 
 
   int t;
   cin>>t;
   while(t--)
    {
        string s;
        cin>>s;
        int n=s.size();
 
        int found=0;
        for(int i=1;i<n-1;i++)
            {
                if(s[i]=='a')
                    {
                        found=i;break;
                    }
            }
        if(found)
            {
             //   cout<<"YES\n";
                cout<<s.substr(0,found)<<" "<<s[found]<<" "<<s.substr(found+1,n-found-1)<<"\n";
            }
        else
            {
                cout<<s[0]<<" "<<s.substr(1,n-2)<<" "<<s[n-1]<<"\n";
            }
    }
    return 0;
}