#include <bits/stdc++.h>
using namespace std;
int main()
{
    //setup();
    int n,z,o,i;
    z = o = 0;
    cin>>n;
    string s;
    cin>>s;
    for(i=0;s[i]!='\0';i++){
        if(s[i]=='1')
            o++;
        else
            z++;
    }
    cout<<abs(z-o)<<endl;
    
    return 0;
}