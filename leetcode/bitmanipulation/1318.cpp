#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        for (int i = 0; i < 32; i++) {
            bool mask = false;
            if (((1 << i) & c) > 0) {
                mask = 1;
            }
            if (!mask) {
                if ((a & (1 << i)) && (b & (1 << i))) {
                    cnt += 2;
                } else if ((a & (1 << i)) || (b & (1 << i))) {
                    cnt += 1;
                }
            } else if (mask) {
                if (!(a & (1 << i)) && !(b & (1 << i))) {
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
};