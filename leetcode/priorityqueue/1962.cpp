#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (auto& i : piles) {
            pq.push(i);
        }
        while (k--) {
            int top = pq.top();
            pq.pop();
            pq.push(top - floor(top / 2));
        }
        int sm = 0;
        while (!pq.empty()) {
            sm += pq.top();
            pq.pop();
        }
        return sm;
    }
};