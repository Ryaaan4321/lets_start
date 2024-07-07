#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>


using namespace std;

class Solution {
public:
    void fucc(int n, string ss, vector<string>& res) {
        if (ss.length() == n) {
            res.push_back(ss);
            return;
        }
        fucc(n, ss + "1", res);

        if (ss.empty() || ss.back() == '1') {
            fucc(n, ss + "0", res);
        }
    }
    vector<string> validStrings(int n) {
     vector<string> result;
        fucc(n,"",result);
        return result;
    }
};