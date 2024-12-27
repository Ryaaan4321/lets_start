#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> ans;
    
    void backtrack(int i, string numpath, long long sum, long long prev, string num, int target) {
        if (i == num.size()) {
            if (sum == target) {
                ans.push_back(numpath);
            }
            return;
        }
        for (int j = i; j < num.size(); j++) {
            if (j > i && num[i] == '0') break;
            
            long long number = stoll(num.substr(i, j - i + 1));
            string path = num.substr(i, j - i + 1);
            
            if (i == 0) {
                backtrack(j + 1, path, number, number, num, target);
            } else {
       
                backtrack(j + 1, numpath + "+" + path, sum + number, number, num, target);
          
                backtrack(j + 1, numpath + "-" + path, sum - number, -number, num, target);
                backtrack(j + 1, numpath + "*" + path, sum - prev + prev * number, prev * number, num, target);
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        backtrack(0, "", 0, 0, num, target);
        return ans;
    }
};
