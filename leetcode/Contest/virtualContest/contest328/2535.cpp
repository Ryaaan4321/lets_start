#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
public:
    int dig(int n) {
        int sm = 0;
        while (n != 0) {
            int val = n % 10;
            sm += val;
            n /= 10;
        }
        return sm;
    }
    int differenceOfSum(vector<int>& a) {
        int sm = 0;
        for (auto it : a) {
            sm += it;
        }
        int sm1 = 0;
        for (int i = 0; i < a.size(); i++) {
            int sm = dig(a[i]);
            sm1 += sm;
        }
        return abs(sm - sm1);
    }
};