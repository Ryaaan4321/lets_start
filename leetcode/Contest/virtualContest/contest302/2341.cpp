#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &a)
    {
        unordered_map<int, int> mpp;
        int pair=0;
        int rem=0;
        for (auto fq : a)
        {
            mpp[fq]++;
        }
        for(auto it:mpp){
            if(!it.second%2){
                rem++;
                pair+=(it.second/2);
            }
        }
        return {pair,rem};

    }
};