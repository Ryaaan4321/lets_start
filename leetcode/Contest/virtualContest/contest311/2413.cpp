#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int smallestEvenMultiple(int n) {
        if (n % 2 == 0) {
            return n;
        } else {
            for (int i = 0; i < n; i++) {
                return n * 2;
            }
        }
        return 1;
    }
};