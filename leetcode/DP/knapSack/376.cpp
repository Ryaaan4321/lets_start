#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>


using namespace std;


class Solution {
public:
    int wiggleMaxLength(vector<int>& a) {
        int f = -1;
        int cnt = 1;
        for (int _ = 0; _ < (int)a.size() - 1; _++) {
            if (a[_] > a[_ + 1]) {
                if (f == -1 || f == 1) {
                    f = 0;
                    cnt++;
                }
            } else if (a[_] < a[_ + 1]) {
                if (f == -1 || f == 0) {
                    f = 1;
                    cnt++;
                }
            }
        }
        return cnt;
        /* bodmoshi ni karega madarchood*/
    }
    int wiggleMaxLength(vector<int>& a) {
        
    }
};