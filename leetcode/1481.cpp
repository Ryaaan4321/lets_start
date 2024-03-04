#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        unordered_map<int, int> mpp;
        for (int &x : arr)
        {
            mpp[x]++;
        }
        vector<int> freqArr;
        for (auto &it : mpp)
        {
            freqArr.push_back(it.second);
        }
        sort(begin(freqArr), end(freqArr));
        for (int i = 0; i < freqArr.size(); ++i)
        {
            k -= freqArr[i];
            if (k < 0)
            {
                return freqArr.size() - i;
            }
        }
        return 0;
    }
    int findLeastNumOfUniqueInts1(vector<int> &arr, int k)
    {
        unordered_map<int, int> mpp;
        for (int &x : arr)
        {
            mpp[x]++;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &it : mpp)
        {
            pq.push(it.second);
        }
        while (!pq.empty())
        {
            k -= pq.top();
            if (k < 0)
            {
                return pq.size();
            }
            pq.pop();
        }
        return 0;
    }
    int findLeastNumOfUniqueInts3(vector<int> &arr, int k)
    {

    }
};