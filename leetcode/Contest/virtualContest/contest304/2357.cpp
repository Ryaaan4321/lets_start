#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
   
    int minimumOperations(vector<int> &a)
    {
        unordered_set<int>s(a.begin(),a.end());
        return s.size()-s.count(0);
    }
};