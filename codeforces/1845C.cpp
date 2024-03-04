#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/* And one day evrything got changed and he became his own companion; */ 

using namespace std;
using str = std::string;

#define x first
#define y second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<vi> vvi;
typedef pair<int, int> pt;

bool isSubsequence(const str &s1, const str &s2) {
    int i = 0, j = 0;
    while (i < s1.length() && j < s2.length()) {
        if (s1[i] == s2[j]) {
            i++;
        }
        j++;
    }
    return i == s1.length();
}
int main(){
   
}