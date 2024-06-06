#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>


using namespace std;

class Solution {
public:
    vector<double> convertTemperature(double cel) {
        vector<double>ans;
        double k=cel+273.15;
        ans.push_back(k);
        double f=cel*1.80+32.00;
        ans.push_back(f);
        return ans;

    }
};