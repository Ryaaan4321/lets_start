#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {

        int preFixMax = values[0];
        int maxScore = 0;

        int n = values.size();

        for(int j=1;j<n;j++){

            maxScore = max(maxScore,preFixMax + values[j]-j);
            preFixMax = max(preFixMax, values[j]+j);
        }
        

        return maxScore;
    }
};