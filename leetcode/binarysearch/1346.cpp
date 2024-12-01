#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(begin(arr),end(arr));
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            int el=arr[i];
            if(el>=1 && binary_search(begin(arr)+i+1,end(arr),2*el)){
                return 1;
            }
            if(el%2==0 && binary_search(begin(arr)+i+1,end(arr),el/2)){
                return 1;
            }
        }
        return 0;
    }
};