#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
// And one day everything got changed and he became his own companion
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
const int MOD = 1e9 + 7;

/*
computing higher powers  with mod */
ll power(int x, int y, int p = MOD)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
        {
            res = (res * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
ll modInverse(int n, int p = MOD)
{
    return power(n, p - 2, p);
}
/* USED TO CALCULATE THE nCr OF HIGHER VALUES*/
ll nCr(int n, int r, int p = MOD)
{
    if (n < r)
    {
        return 0;
    }
    if (r == 0)
    {
        return 1;
    }
    vector<int> fac(n + 1, 0);
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = (fac[i - 1] * i) % p;
    }
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p)) % p;
}
bool primeNo(int n)
{
    bool prime = true;
    /*so in this for loop we are only going till sqrt of n so the TC of this for loop will  be O(sqrt(n))*/
    for (int i = 2; i * i < n; i++)
    {
        /*for(int i=2;i<n;i++){ /* and in the case of this it will be O(n)*/
        if (n % i == 0)
        {
            prime = false;
            break;
        }
    }
    return prime;
}
/*Another method to check that the number is prime or not is sieve of erothenisis*/
vector<bool> solve(int sz)
{

    vector<bool> sieve(sz, 1); // assuming initially all the values from 1 to 15 are the prime values;
    /*bt not the 1 and 2 so ..*/
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i < sz; i++)
    {
        if (sieve[i] == 0)
            continue;                       // If 'i' is marked as non-prime, skip it.
        for (int j = i * i; j < sz; j += i) /*   Mark the multiples of 'i' as non-prime*/
        {
            /*so the point over here is if any number has previously came as a multiple
            of the prime no then there is no need to check
             it is a composite number an for example lets assume
              we have started from 1 and going till 15 (int sz=15)
              so marking sieve[0] and sieve[1] as a composite becasue
              they are the composite
             numbers and here to recognise the number
              is prime or composite then for that
              (point to note:: here in this code i
               have taken boolean vector and in that if
               any index is filled with 1 then its prime
               otherwise it will be a composite number)
               so i think u got how  i have used boolean
                array to represent the number is composite or prime
               so lets suppose when we are going from 1 to 15 the 4
               will come as a first composite number we know that
               it is a composite number bt how does code willl get to know
               so for that in the 2nd loop we are checking if it is a multiple
                of a prime number (and in the case of 4 it is a multiple of 2 which means
                 it can also be divided by 2 so it cant be a prime number because as we all know
                  that prime numbers have only 2 facotrs either 1 or number itself
                same for 6 6 is a multiple of 2 and 3
                same for 8 it is also a multiple of 2 and 4
                and so on and so forth
                bt in the case of prime number we have 3  it is not a multiple of any number
                 except 1 or 3 so it will be marked as prime or (1) in that boolean array;
                and so on and so forth for all the prime numbers
                and the reason of using this algorithm is the time complexity
                so as u  have seen in the code that we are only checking if
                 they are  the multiples of i or otherwise we are skipping that element
                and hence the timecomplexity wll reduce from O(log(nlog(n)));
                which is much better thatn O(logn) so thats  it that is the sieve of
                erothenis algorithm i hope u find it useful and i will love to hear ur reviews on this
                and the areas where i can improve p;
                and one more thing if u want the editorail in any other alogorithms
                (please not dp  dp mein meri phat jati hai and also not the devlopment well i wanna say fuck devlopment) bt i ccan give it a try p;
                u can tell me i will love to make one;

                )


              */
            sieve[j] = 0;
        }
    }
    return sieve;
}

int32_t main()
{
    int n;
    cin >> n;
    vector<bool> ans = solve(n);
    for (int i = 1; i < n; i++)
    {
        cout << i << " " << ans[i] << "\n";
    }
    for (int i = 0; i < n; i++)
    {
        int val = 0;
        cin >> val;
        if (ans[i] == 0)
            cout << "Composite\n";
        else
            cout << "Prime\n";
    }
    return 0;
}