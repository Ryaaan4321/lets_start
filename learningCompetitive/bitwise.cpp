#include <iostream>
#include <vector>
#include <algorithm> // for std::sort
#include <utility>
#include <bits/stdc++.h> // for std::pair, std::make_pair
/*And one day evrything got changed and he became his own companion;*/

using namespace std;

/*debug macro starts here*/
int recur_depth = 0;
#ifdef DEBUG
#define dbg(x)                                                                                                                         \
    {                                                                                                                                  \
        ++recur_depth;                                                                                                                 \
        auto x_ = x;                                                                                                                   \
        --recur_depth;                                                                                                                 \
        cerr << string(recur_depth, '\t') << "\e[91m" << __func__ << ":" << __LINE__ << "\t" << #x << " = " << x_ << "\e[39m" << endl; \
    }
#else
#define dbg(x)
#endif
template <typename Ostream, typename Cont>
typename enable_if<is_same<Ostream, ostream>::value, Ostream &>::type operator<<(Ostream &os, const Cont &v)
{
    os << "[";
    for (auto &x : v)
    {
        os << x << ", ";
    }
    return os << "]";
}
template <typename Ostream, typename... Ts>
Ostream &operator<<(Ostream &os, const pair<Ts...> &p)
{
    return os << "{" << p.first << ", " << p.second << "}";
}
/*debug macro ends here*/
#define ll long long
#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define Long_MAX_VALUE 0x7fffffffffffffffL
#define Long_MIN_VALUE 0x8000000000000000L
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)

typedef vector<pair<int, int>> vpi;
typedef vector<int> vi;
typedef vector<int> vli;
typedef vector<vi> vvi;
/*
----------------------------------------------- THINGS TO REMEMBER ----------------------------------------------------------------
--------------------- TLE : INFINITE LOOP  ,OR CHECK THE CONSTRAINTS AND THE LOOPS--------------------------------------------------------------------------------
--------------------- MLE :  CHCK FOR THE SIZE OF THE MEMORY------------------------------------------------------------------------------------------------------
--------------------- RE : POPING THE EMPTY ARRAY OR THE STACK ,QUEUE OR THE INDEX BOUNDS----------------------------------------------------------------------------
*/

string getBinary(int x)
{
    bitset<4> b(x); /*so this can be used to convert the number into the bits and inside this we define the size of it if it is
     16 size than 15 - {0000000000001111} it converted it into 16 size bits to it and
     if we have used 8 size than for 15 it will be represented as {00001111} so i think u got
      this lets jump into the bitwise operators
     */
    return b.to_string();
}
int andOp(int a, int b)
{
    int c = a & b;
    int cc = a and b;
    // this lso works same;
    /* a   b    a&b
    --------------------------
       1   0     0
       0   0     0
       0   1     0
       1   1     1
    */
    /*and is the operation where the result of the bit will be 1 only when
   both the bits are 1 and in all othercases this will be 0;*/
    return cc;
}
int orOp(int a, int b)
{
    int c = a | b;
    /*so or works totally something similar to the and operation
    where if both the bits are 0 than it will be 0 otherwise it will be 1
       a   b    a|b
    --------------------------
       1   0     1
       0   0     0
       0   1     1
       1   1     1

    */
    int cc = a or b;
    return c;
}
int xorOp(int a, int b)
{
    int c = a ^ b;
    /* so the working of the xor operator is diffrent the table of the xor operation is
    diffrent bits than 1 otherwise than it will be 1;

       a   b    a^b
    --------------------------
       1   0     1
       0   1     1
       0   0     0
       1   1     0

       if both the bits are same then it is 0 otherwise it will be 1;


        int pXor;
    if (a % 4 == 1)
    {
        (O(1)) solution to find the xorr of the number
        pXor = a - 1;
    }
    else if (a % 4 == 2)
    {
        pXor = 1;
    }
    else if (a % 4 == 3)
    {
        pXor = a;
    }
    else
    {
        pXor = 0;
    }

    */
}
int leftShift(int a)
{
    int c = a << 1;
    return c;

    /*left shifting is something like (b=b*2^(i+x))
    or we just simply take a power of the place we waant to shift and muliply it with the number
    for example we have 4
    we want to shift it by 1 place so it will be equal to 8 because 2^1 is 2 and 2* 4 = 8
    and if we want to shift it by two place then it will be 16 becuase 2^2 = 4 then it will be 4*4=16 */
}
int rightShift(int a)
{
    int c = a >> 2;
    return c;
    /*as in the left shift we are multiplying the number with its power bt for right
    shift we do a opposite we divide it with the 2^x thats it
    for 4 = 2;
    for 8 = 4
    for 16 = 8 when we are doing the 1 rightshift
    bt in case we are doing two right shift then ?
    then it will be
    for 4 = 1;
    for 8 = 2 ;
    for 16 = 4 and it goes on and on*/
}
int main()
{

    int a;
    cin >> a;
    cout << getBinary(a) << endl;

    int c = leftShift(a);
    cout << getBinary(c) << endl;
    cout << c <<"\n";
}