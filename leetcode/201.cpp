#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        while (right!=0)
        {
            right=right&right-1;
            /* code */
        }
        return right;
        
    }
};