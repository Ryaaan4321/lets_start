#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;

#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define Long_MAX_VALUE 0x7fffffffffffffffL
#define Long_MIN_VALUE 0x8000000000000000L

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<vi> vvi;


int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

int lcm(int x, int y) {
    return x * y / gcd(x, y);
}


int solutionNaive() {
    int sumNumbers = 0;
    int sumSquares = 0;

    for (int i = 0; i <= 100; i++) {
        sumNumbers += i;
        sumSquares += i * i;
    }
     return sumNumbers*sumNumbers-sumSquares;

   
}

int main() {
    int x , y;
    cin>>x >>y;
    int result = gcd(x,y);
    std::cout << result << std::endl;

    return 0;
}






 



