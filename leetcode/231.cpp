#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        int total = __builtin_popcount(n);
        if(total==0){return false;}
        else if (total >1 || n<0)
        {
            return false;
        }
        
        return true;
    }
};