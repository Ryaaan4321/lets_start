#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    string removeKdigits(string s, int k)
    {
        stack<int> st;
        for (char ch : s)
        {
            int num = ch - '0';
            st.push(num);
        }
        while (k--)
        {
            st.pop();
            
            /* code */
        }
        
    }
};