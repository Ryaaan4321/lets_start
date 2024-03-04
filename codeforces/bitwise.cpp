#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
// And one day evrything got changed and he became his own companion;

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<vi> vvi;
// refrence link
// https://www.geeksforgeeks.org/check-if-a-number-is-odd-or-even-using-bitwise-operators/

bool isEven(int n)
{
    if ((n ^ 1) == n + 1)
    {
        return true;
    }
    return false;
}
bool isOdd(int n)
{
    if ((n ^ 1) == n - 1)
    {
        return true;
    }
    return false;
}
// And Operation to check that number is even or odd;
bool isEvenOddAnd(int n)
{
    if ((n & 1) == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    
        int n;
        if(isOdd(n)){
            for(int i=0;i<n;++i){
                cout<<4<<"\n";
            }
        }else{
            for(int i=1;i<=n-2;++i){
                cout<<4<<"\n";
            }
        }

       
    
    return 0;
}